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

// Funcții ajutătoare pentru a face codul Bison mai curat
void enter_scope(string name) {
    current = new SymTable(name, current);
}

void exit_scope() {
    if (current) {
        current->printTable(tableFile); // Scriem în fișier înainte să "pierdem" tabelul
        SymTable* parent = current->getParent();
        // Nu ștergem pointerul 'current' aici dacă vrem să păstrăm tabelele în memorie, 
        // dar pentru acest exercițiu doar îl scoatem din stivă.
        // delete current; // Decomment dacă vrei să eliberezi memoria imediat
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
    int IntVal;
    float FloatVal;
    bool BoolVal;
}

/* Tokens */
%token NEW PRINT CLASS RETURN BGIN END ASSIGN IF ELSE WHILE FOR CMP 
%token <Str> ID TYPE STRING
%token <IntVal> NR
%token <FloatVal> FNR
%token <BoolVal> BVAL

/* Precedenta */
%left '|'
%left '&'
%left CMP
%left '+' '-'
%left '*' '/' '%'

%%

program
    : { enter_scope("Global"); } /* Inițializare Global Scope */
      global_list main_block
      { 
          cout << "Program is correct" << endl; 
          exit_scope(); /* Închide Global Scope la final */
      }
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
        /* Adăugăm numele clasei în scope-ul PĂRINTE (Global) */
        current->addSymbol("class", *$2, "class");
        /* Intrăm în scope-ul clasei */
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
    : TYPE ID '(' 
      { 
         current->addSymbol(*$1, *$2, "function");
         
         enter_scope("Function: " + *$2); 
      }
      param_list ')' '{' func_body '}'
      { 
        cout << "Functie identificata: " << *$1 << " " << *$2 << endl;
        exit_scope(); 
      }
      
    | TYPE ID '(' ')' 
      { 
         current->addSymbol(*$1, *$2, "function");
         enter_scope("Function: " + *$2); 
      }
      '{' func_body '}'
      { 
         cout << "Functie identificata fara params" << endl; 
         exit_scope();
      }
      
    | ID ID '(' 
      { 
         current->addSymbol(*$1, *$2, "constructor");
         enter_scope("Constructor: " + *$2); 
      }
      param_list ')' '{' func_body '}'
      { exit_scope(); }
      
    | ID ID '(' ')' 
      { 
         current->addSymbol(*$1, *$2, "constructor");
         enter_scope("Constructor: " + *$2); 
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
         
      }
    | ID ID
      {
         current->addSymbol(*$1, *$2, "param");
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
    : ID ASSIGN expr { 
        if(!current->existsId(*$1)) 
            cout << "Error: Variable " << *$1 << " not declared!" << endl;
      }
    | ID '.' ID ASSIGN expr
    ;

call_stmt
    : ID '(' args_list ')'
    | ID '.' ID '(' args_list ')'
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

var_decl
    : TYPE ID ';' 
      { 
        current->addSymbol(*$1, *$2, "variable"); 
      }
    | TYPE ID ASSIGN expr ';'
      { 
        current->addSymbol(*$1, *$2, "variable"); 
      }
    ;

object_decl
    : ID ID ';'
      {
        current->addSymbol(*$1, *$2, "object");
      }
    | ID ID ASSIGN expr ';'
      {
        current->addSymbol(*$1, *$2, "object");
      }
    ;

expr
    : expr '+' expr
    | expr '-' expr
    | expr '*' expr
    | expr '/' expr
    | expr '%' expr
    | expr CMP expr
    | expr '&' expr
    | expr '|' expr
    | '(' expr ')'
    | ID { 
        if(!current->existsId(*$1)) 
             cout << "Error: ID " << *$1 << " used but not declared (line " << yylineno << ")" << endl; 
      }
    | ID '.' ID
    | call_stmt
    | NR
    | FNR
    | BVAL
    | STRING
    | NEW ID '(' args_list ')'
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
        if (!yyin) {
            cerr << "Nu pot deschide fisierul " << argv[1] << endl;
            return 1;
        }
    }

    yyparse();
    
    tableFile.close(); // Închidem fișierul de ieșire
    return 0;
}