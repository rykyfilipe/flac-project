%{
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "SymTable.h"

using namespace std;

extern int yylex();
void yyerror(const char* s);
extern FILE* yyin;
extern int yylineno;

// Variabile globale pentru gestionarea tabelelor
SymTable* current = NULL;
ofstream tableFile("tables.txt");

// Reținem numele funcției curente pentru a adăuga parametrii în tabela părinte
string currentFuncName = "";

void enter_scope(string name) {
    current = new SymTable(name, current);
}

void exit_scope() {
    if (current) {
        current->printTable(tableFile);
        SymTable* parent = current->getParent();
        current = parent;
    }
}
%}

%code requires {
    #include <string>
    using namespace std;
}

%union {
    std::string* Str;
    /* NR, FNR și BVAL vor fi tratate ca Str pentru a stoca valoarea lor textuală în tabelă */
}

/* Tokens */
%token NEW PRINT CLASS RETURN BGIN END ASSIGN IF ELSE WHILE FOR 
%token <Str> ID TYPE STRING NR FNR BVAL CMP

/* Precedenta */
%left '|'
%left '&'
%left CMP
%left '+' '-'
%left '*' '/' '%'

/* Tipuri pentru reguli ne-terminale */
%type <Str> expr

%%
program
    : global_scope_start global_list main_block
      { 
          cout << "Program is correct" << endl; 
          exit_scope(); 
      }
    ;

global_scope_start
    : /* empty */ { enter_scope("Global"); }
    ;
global_list
    : /* empty */
    | global_list class_decl
    | global_list func_decl
    | global_list var_decl
    | global_list object_decl
    ;

main_block
    : BGIN { enter_scope("Main"); } stmt_list END { exit_scope(); }
    ;

/* CLASS DECLARATION */
class_decl
    : CLASS ID 
      { 
        current->addSymbol("class", *$2, "class");
        enter_scope("Class: " + *$2); 
      }
      '{' class_body '}'
      { 
        cout << "Class identified: " << *$2 << endl; 
        exit_scope(); 
      }
    ;

class_body
    : /* empty */
    | class_body var_decl
    | class_body func_decl
    ;

func_decl
    /* 1. Funcție cu tip primitiv + Parametri */
    : TYPE ID '(' 
      { 
         current->addSymbol(*$1, *$2, "function");
         currentFuncName = *$2;
         enter_scope("Function: " + *$2); 
      }
      param_list ')' '{' func_body '}'
      { currentFuncName = ""; exit_scope(); }

    /* 2. Funcție cu tip primitiv, FĂRĂ Parametri */
    | TYPE ID '(' ')' 
      { 
         current->addSymbol(*$1, *$2, "function");
         enter_scope("Function: " + *$2); 
      }
      '{' func_body '}'
      { exit_scope(); }

    /* 3. Funcție care returnează o Clasă (ID) + Parametri */
    | ID ID '(' 
      { 
         current->addSymbol(*$1, *$2, "function");
         currentFuncName = *$2;
         enter_scope("Function: " + *$2); 
      }
      param_list ')' '{' func_body '}'
      { currentFuncName = ""; exit_scope(); }

    /* 4. Funcție care returnează o Clasă (ID), FĂRĂ Parametri */
    | ID ID '(' ')' 
      { 
         current->addSymbol(*$1, *$2, "function");
         enter_scope("Function: " + *$2); 
      }
      '{' func_body '}'
      { exit_scope(); }

    /* 5. Constructor + Parametri (ex: Person(int a)) */
    | ID '(' 
      { 
         current->addSymbol("class_type", *$1, "constructor");
         currentFuncName = *$1;
         enter_scope("Constructor: " + *$1); 
      }
      param_list ')' '{' func_body '}'
      { currentFuncName = ""; exit_scope(); }

    /* 6. Constructor FĂRĂ Parametri (ex: Person()) */
    | ID '(' ')' 
      { 
         current->addSymbol("class_type", *$1, "constructor");
         enter_scope("Constructor: " + *$1); 
      }
      '{' func_body '}'
      { exit_scope(); }
    ;

func_body
    : decl_list stmt_list
    ;

decl_list
    : /* empty */
    | decl_list var_decl
    ;

param_list
    : param_decl
    | param_list ',' param_decl
    ;

param_decl
    : TYPE ID
      {
          current->addSymbol(*$1, *$2, "param");
          // Adăugăm tipul parametrului în fișa funcției din scope-ul părinte
          if(current->getParent() && currentFuncName != "") {
              current->getParent()->addFuncParam(currentFuncName, *$1);
          }
      }
    | ID ID
      {
          current->addSymbol(*$1, *$2, "param");
          if(current->getParent() && currentFuncName != "") {
              current->getParent()->addFuncParam(currentFuncName, *$1);
          }
      }
    ;

stmt_list
    : /* empty */
    | stmt_list stmt
    ;

stmt
    : assign_stmt ';'
    | control_stmt
    | call_stmt ';'
    | PRINT '(' expr ')' ';'
    | RETURN expr ';'
    ;

assign_stmt
    : ID ASSIGN expr 
      { 
        if(!current->existsId(*$1)) 
            cout << "Error: Variable " << *$1 << " not declared!" << endl;
        else
            current->updateValue(*$1, *$3); // Actualizăm valoarea
      }
    ;

control_stmt
    : IF '(' expr ')' '{' 
      { enter_scope("If_Block"); } 
      stmt_list '}' 
      { exit_scope(); }
    | WHILE '(' expr ')' '{' 
      { enter_scope("While_Block"); } 
      stmt_list '}' 
      { exit_scope(); }
    ;

call_stmt
    : ID '(' args_list ')'
      {
          if(!current->existsId(*$1)) {
              cout << "Error: Function " << *$1 << " called but not defined (line " << yylineno << ")" << endl;
          }
      }
    | ID '.' ID '(' args_list ')'
      {
          // Verifici dacă obiectul (primul ID) există
          if(!current->existsId(*$1)) {
              cout << "Error: Object " << *$1 << " undeclared (line " << yylineno << ")" << endl;
          }
      }
    ;

var_decl
    : TYPE ID ';' 
      { 
        current->addSymbol(*$1, *$2, "variable"); 
      }
    | TYPE ID ASSIGN expr ';'
      { 
        current->addSymbol(*$1, *$2, "variable", *$4); 
      }
    
    ;

object_decl
    : ID ID ';'
      {
        current->addSymbol(*$1, *$2, "object");
      }
    | ID ID ASSIGN expr ';'
      {
        current->addSymbol(*$1, *$2, "object", *$4);
      }
    ;

expr
    : expr '+' expr { $$ = new string(*$1 + "+" + *$3); }
    | expr '-' expr { $$ = new string(*$1 + "-" + *$3); }
    | expr '*' expr { $$ = new string(*$1 + "*" + *$3); }
    | expr '/' expr { $$ = new string(*$1 + "/" + *$3); }
    | expr CMP expr { $$ = new string(*$1 + *$2 + *$3); }
    | '(' expr ')'  { $$ = $2; }
    | ID { 
        if(!current->existsId(*$1)) 
             cout << "Error: ID " << *$1 << " undeclared (line " << yylineno << ")" << endl; 
        $$ = $1;
      }
    | NR     { $$ = $1; }
    | FNR    { $$ = $1; }
    | BVAL   { $$ = $1; }
    | STRING { $$ = $1; }
    | call_stmt { $$ = new string("call"); }
    | NEW ID '(' args_list ')'
      {
          // Verificăm dacă clasa (tipul obiectului) există în tabelă
          if(!current->existsId(*$2)) {
              cout << "Error: Class " << *$2 << " not defined for NEW (line " << yylineno << ")" << endl;
          }
          // Returnăm reprezentarea textuală a apelului de constructor
          $$ = new string("new " + *$2 + "(...)");
      }
   
    ;

args_list
    : /* empty */
    | expr
    | args_list ',' expr
    ;

%%

void yyerror(const char* s) {
    cout << "error: " << s << " at line: " << yylineno << endl;
}

int main(int argc, char** argv) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
    }
    yyparse();
    tableFile.close();
    return 0;
}