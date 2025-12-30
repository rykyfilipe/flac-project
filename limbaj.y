%{
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

extern int yylex();
void yyerror(const char* s);
extern FILE* yyin;
extern int yylineno;
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

%start progr

%token <Str> ID TYPE STRING
%token <IntVal> NR BVAL
%token <FloatVal> FNR
%token CLASS RETURN BGIN END ASSIGN IF ELSE WHILE FOR CMP 

%%

progr
    : declarations main
    ;

declarations
    : decl
    | declarations decl
    | declarations class
    ;

decl
    : TYPE ID ';' {
        cout << "variabila cu tipul " << *$1 << " si id-ul: " << *$2 << endl;
        delete $1; delete $2;
      }
    | TYPE ID '(' list_param ')' ';' {
        cout << "functie cu tipul " << *$1 << " si id-ul: " << *$2 << endl;
        delete $1; delete $2;
      }
    | TYPE ID '(' ')' ';' {
        cout << "functie cu tipul " << *$1 << " si id-ul: " << *$2 << " si fara params" << endl;
        delete $1; delete $2;
      }
    ;

class
    : CLASS ID '{' decl '}' {
        cout << "clasa cu id-ul: " << *$2 << endl;
        delete $2;
      }
    ;

list_param
    : param
    | list_param ',' param
    ;

param
    : TYPE ID {
        cout << "parametru cu tipul: " << *$1 << " si id-ul: " << *$2 << endl;
        delete $1; delete $2;
      }
    ;

main
    : BGIN list_statements END
    ;



statement
    : ID ASSIGN expression ';' { 
        cout << "Atribuire la variabila " << *$1; 
        delete $1; 
      }
    | IF '(' condition ')' block ELSE block { cout << "S-a detectat un IF-ELSE\n"; }
    | WHILE '(' condition ')' block { cout << "S-a detectat un WHILE\n"; }
    | FOR '(' ID ASSIGN expression ';' condition ';' ID ASSIGN expression  ')' block { cout << "S-a detectat un FOR\n"; }
    | ID '(' call_list ')' ';' { cout << "Apel functie: " << *$1 << endl; delete $1; }
    ;


expression
    : ID { cout << " id_e : " << *$1 << endl; delete $1; }
    | NR {cout << " val : " << $1 << endl; }
    | FNR {cout << " val : " << $1 << endl; }
    | BVAL{cout << " val : " << $1 << endl; }
    ;

condition
    : expression CMP expression
    | expression
    ;

block
    : '{' list_statements '}'
    | statement 
    ;

list_statements
    : statement 
    | list_statements statement 
    ;

call_list
    : call_list_value
    | call_list ',' call_list_value
    ;

call_list_value : ID
    | NR
    | BVAL {cout << "bool detected";}
    | FNR
    | STRING
    | ID '(' call_list ')'
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
