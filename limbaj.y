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

SymTable* current = NULL;
ofstream tableFile("tables.txt");
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

void sem_error(string msg) {
    cout << "Semantic Error at line " << yylineno << ": " << msg << endl;
}
%}

%code requires {
    #include <string>
    #include <vector>
    using namespace std;

    struct ExprInfo {
        string type;
        string value;
    };
}

%union {
    std::string* Str;
    ExprInfo* EInfo;
    std::vector<string>* ArgList;
}

%token NEW PRINT CLASS RETURN BGIN END ASSIGN IF ELSE WHILE FOR 
%token <Str> ID TYPE STRING NR FNR BVAL CMP

%left CMP
%left '+' '-'
%left '*' '/' '%'

%type <EInfo> expr
%type <ArgList> args_list

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

/* DECLARATII CLASE - Doar in Global Scope conform cerintei */
class_decl
    : CLASS ID 
      { 
        if(!current->addSymbol("class", *$2, "class"))
            sem_error("Class " + *$2 + " already defined.");
        
        SymTable::classRegistry[*$2] = {*$2, {}};
        enter_scope("Class: " + *$2); 
      }
      '{' class_body '}'
      { exit_scope(); }
    ;

class_body
    : /* empty */
    | class_body var_decl
    | class_body func_decl
    ;

/* DECLARATII FUNCTII */
func_decl
    : TYPE ID '(' 
      { 
         if(!current->addSymbol(*$1, *$2, "function"))
            sem_error("Function " + *$2 + " already defined.");
         currentFuncName = *$2;
         enter_scope("Function: " + *$2); 
      }
      param_list ')' '{' func_body '}'
      { currentFuncName = ""; exit_scope(); }

    | TYPE ID '(' ')' 
      { 
         if(!current->addSymbol(*$1, *$2, "function"))
            sem_error("Function " + *$2 + " already defined.");
         enter_scope("Function: " + *$2); 
      }
      '{' func_body '}'
      { exit_scope(); }

    | ID ID '(' 
      { 
         if(!current->addSymbol(*$1, *$2, "function"))
            sem_error("Function " + *$2 + " already defined.");
         currentFuncName = *$2;
         enter_scope("Function: " + *$2); 
      }
      param_list ')' '{' func_body '}'
      { currentFuncName = ""; exit_scope(); }

    | ID ID '(' ')' 
      { 
         if(!current->addSymbol(*$1, *$2, "function"))
            sem_error("Function " + *$2 + " already defined.");
         enter_scope("Function: " + *$2); 
      }
      '{' func_body '}'
      { exit_scope(); }

    | ID '(' 
      { 
         current->addSymbol("class_type", *$1, "constructor");
         currentFuncName = *$1;
         enter_scope("Constructor: " + *$1); 
      }
      param_list ')' '{' func_body '}'
      { currentFuncName = ""; exit_scope(); }

    | ID '(' ')' 
      { 
         current->addSymbol("class_type", *$1, "constructor");
         enter_scope("Constructor: " + *$1); 
      }
      '{' func_body '}'
      { exit_scope(); }
    ;

/* Restricție: variabilele locale doar la începutul funcției */
func_body : decl_list stmt_list ;
decl_list : /* empty */ | decl_list var_decl ;

param_list
    : param_decl
    | param_list ',' param_decl
    ;

param_decl
    : TYPE ID
      {
          if(!current->addSymbol(*$1, *$2, "param"))
             sem_error("Parameter " + *$2 + " duplicated.");
          if(current->getParent() && currentFuncName != "")
              current->getParent()->addFuncParam(currentFuncName, *$1);
      }
    | ID ID
      {
          if(!current->addSymbol(*$1, *$2, "param"))
             sem_error("Parameter " + *$2 + " duplicated.");
          if(current->getParent() && currentFuncName != "")
              current->getParent()->addFuncParam(currentFuncName, *$1);
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
      { /* Predefined function logic */ }
    | RETURN expr ';'
    ;

assign_stmt
    : ID ASSIGN expr 
      { 
        IdInfo* info = current->getSymbolInfo(*$1);
        if(!info) 
            sem_error("Variable " + *$1 + " not declared!");
        else if(info->type != $3->type && $3->type != "error")
            sem_error("Type mismatch: cannot assign " + $3->type + " to " + info->type + " (" + *$1 + ")");
        else
            current->updateValue(*$1, $3->value);
      }

    | ID '.' ID ASSIGN expr
      {
          // 1. Verificăm dacă obiectul (primul ID) este declarat
          IdInfo* objInfo = current->getSymbolInfo(*$1);
          if(!objInfo) {
              sem_error("Object '" + *$1 + "' is not declared.");
          } 
          else {
              // 2. Luăm numele clasei din tipul obiectului
              string className = objInfo->type;

              // 3. Verificăm dacă clasa există în registrul de clase
              if(SymTable::classRegistry.count(className)) {
                  auto& members = SymTable::classRegistry[className].members;

                  // 4. Verificăm dacă field-ul (al doilea ID) există în acea clasă
                  if(members.count(*$3)) {
                      string fieldType = members[*$3].type;

                      // 5. Verificăm compatibilitatea de tip între field și expresie
                      if(fieldType != $5->type && $5->type != "error") {
                          sem_error("Type mismatch: Field '" + *$3 + "' of class '" + className + 
                                    "' is " + fieldType + ", but expression is " + $5->type);
                      }
                      // Succes semantic
                  } else {
                      sem_error("Class '" + className + "' does not have a member named '" + *$3 + "'");
                  }
              } else {
                  sem_error("Variable '" + *$1 + "' (type " + className + ") does not refer to a valid class.");
              }
          }
      }
    ;

    ;

control_stmt
    : IF '(' expr ')' '{' { enter_scope("If_Block"); } stmt_list '}' { exit_scope(); }
    | WHILE '(' expr ')' '{' { enter_scope("While_Block"); } stmt_list '}' { exit_scope(); }
    ;

call_stmt
    : ID '(' args_list ')'
      {
          IdInfo* info = current->getSymbolInfo(*$1);
          if(!info) sem_error("Function " + *$1 + " not defined.");
          else {
              if(info->paramTypes.size() != $3->size()) 
                  sem_error("Function " + *$1 + " expects " + to_string(info->paramTypes.size()) + " args.");
              else {
                  for(size_t i=0; i<$3->size(); ++i)
                      if(info->paramTypes[i] != (*$3)[i])
                          sem_error("Arg mismatch for " + *$1);
              }
          }
      }
    | ID '.' ID '(' args_list ')'
      {
          IdInfo* obj = current->getSymbolInfo(*$1);
          if(!obj) sem_error("Object " + *$1 + " undeclared.");
          else {
              string cls = obj->type;
              if(SymTable::classRegistry.count(cls)) {
                  if(!SymTable::classRegistry[cls].members.count(*$3))
                      sem_error("Member " + *$3 + " not found in class " + cls);
              }
          }
      }
    ;

var_decl
    : TYPE ID ';' 
      { 
        if(!current->addSymbol(*$1, *$2, "variable"))
            sem_error("Variable " + *$2 + " redeclared.");
      }
    | TYPE ID ASSIGN expr ';'
      { 
        if(*$1 != $4->type && $4->type != "error")
            sem_error("Type mismatch in declaration of " + *$2);
        if(!current->addSymbol(*$1, *$2, "variable", $4->value))
            sem_error("Variable " + *$2 + " redeclared.");
      }
    ;

object_decl
    : ID ID ';' 
      { if(!current->addSymbol(*$1, *$2, "object")) sem_error("Object " + *$2 + " redeclared."); }
    ;

expr
    : expr '+' expr {
        if($1->type != $3->type) { sem_error("Type mismatch: " + $1->type + " + " + $3->type); $$ = new ExprInfo{"error",""}; }
        else $$ = new ExprInfo{$1->type, ""};
    }
    | expr '-' expr {
        if($1->type != $3->type) { sem_error("Type mismatch: " + $1->type + " - " + $3->type); $$ = new ExprInfo{"error",""}; }
        else $$ = new ExprInfo{$1->type, ""};
    }
    | expr '*' expr {
        if($1->type != $3->type) { sem_error("Type mismatch: " + $1->type + " * " + $3->type); $$ = new ExprInfo{"error",""}; }
        else $$ = new ExprInfo{$1->type, ""};
    }
    | expr '/' expr {
        if($1->type != $3->type) { sem_error("Type mismatch: " + $1->type + " / " + $3->type); $$ = new ExprInfo{"error",""}; }
        else $$ = new ExprInfo{$1->type, ""};
    }
    | expr CMP expr {
        if($1->type != $3->type) { sem_error("Comparison type mismatch"); $$ = new ExprInfo{"error",""}; }
        else $$ = new ExprInfo{"bool", ""};
    }
    | '(' expr ')' { $$ = $2; }
    | ID {
        string t = current->getType(*$1);
        if(t == "") { sem_error("Undefined variable: " + *$1); t = "error"; }
        $$ = new ExprInfo{t, ""};
    }
    | ID '(' args_list ')' {
        IdInfo* info = current->getSymbolInfo(*$1);
        if(!info) { sem_error("Function " + *$1 + " undefined"); $$ = new ExprInfo{"error",""}; }
        else $$ = new ExprInfo{info->type, ""};
    }
    | ID '.' ID {
        IdInfo* obj = current->getSymbolInfo(*$1);
        if(!obj) { sem_error("Object " + *$1 + " undefined"); $$ = new ExprInfo{"error",""}; }
        else {
            string cls = obj->type;
            if(SymTable::classRegistry.count(cls) && SymTable::classRegistry[cls].members.count(*$3))
                $$ = new ExprInfo{SymTable::classRegistry[cls].members[*$3].type, ""};
            else { sem_error("Field " + *$3 + " not in class"); $$ = new ExprInfo{"error",""}; }
        }
    }
    | NR     { $$ = new ExprInfo{"int", ""}; }
    | FNR    { $$ = new ExprInfo{"float", ""}; }
    | BVAL   { $$ = new ExprInfo{"bool", ""}; }
    | STRING { $$ = new ExprInfo{"string", ""}; }
    | NEW ID '(' args_list ')' {
        if(SymTable::classRegistry.count(*$2) == 0) sem_error("Class " + *$2 + " not defined");
        $$ = new ExprInfo{*$2, ""};
    }
    ;

args_list
    : /* empty */ { $$ = new vector<string>(); }
    | expr { $$ = new vector<string>(); $$->push_back($1->type); }
    | args_list ',' expr { $1->push_back($3->type); $$ = $1; }
    ;

%%

void yyerror(const char* s) {
    cout << "Syntax Error: " << s << " at line: " << yylineno << endl;
}

int main(int argc, char** argv) {
    if (argc > 1) yyin = fopen(argv[1], "r");
    yyparse();
    tableFile.close();
    return 0;
}