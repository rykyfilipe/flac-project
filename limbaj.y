%{
#include <iostream>
#include <string>
#include <stdio.h>
#include "SymTable.h"

using namespace std;

extern int yylex();
void yyerror(const char* s);
extern FILE* yyin;
extern int yylineno;
class SymTable* current;
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

%start program

%token NEW PRINT CLASS RETURN BGIN END ASSIGN IF ELSE WHILE FOR CMP 
%token <Str> ID TYPE STRING
%token <IntVal> NR
%token <FloatVal> FNR
%token <BoolVal> BVAL


/* precedenta operatorilor */
%left '|'
%left '&'
%left CMP
%left '+' '-'
%left '*' '/' '%'

%%

program
    : global_list main_block
      { cout << "Program is corect" << endl; }
    ;

global_list
    : /* empty */
    | global_list class_decl
    | global_list func_decl
    | global_list var_decl
    | global_list object_decl

    ;

main_block
    : BGIN stmt_list END
    ;

class_decl
    : CLASS ID '{' class_body '}'
      { cout << "Class identified: " << *$2 << endl; }
    ;

class_body
    : /* empty */
    | class_body var_decl
    | class_body func_decl
    ;

func_decl
    : TYPE ID '(' param_list ')' '{' func_body '}'
      { cout << "Functie identificata: " << *$1 << " " << *$2 << endl;
        
       }
    | TYPE ID '(' ')' '{' func_body '}'
      { cout << "Functie identificata fara params: " << *$1 << " " << *$2 << endl; }
    | ID ID '(' param_list ')' '{' func_body '}'
      { cout << "Constructor identificat: " << *$1 << " " << *$2 << endl; }
    | ID ID '(' ')' '{' func_body '}'
      { cout << "Constructor identificat fara params: " << *$1 << " " << *$2 << endl; }
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
    | ID ID
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
    | ID '.' ID ASSIGN expr
    ;

call_stmt
    : ID '(' args_list ')'
    | ID '.' ID '(' args_list ')'
    ;

control_stmt
    : IF '(' expr ')' '{' stmt_list '}'
    | WHILE '(' expr ')' '{' stmt_list '}'
    ;

var_decl
    : TYPE ID ';'
    | TYPE ID ASSIGN expr ';'
    ;

object_decl
    : ID ID ';'
    | ID ID ASSIGN expr ';'
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
    | ID
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
    return 0;
}
