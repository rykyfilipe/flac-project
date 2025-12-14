%{
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

extern int yylex();
void yyerror(const char* s);
extern FILE* yyin;
%}

%code requires {
    #include <string>
    using namespace std;
}

%start progr

%union {
    std::string* Str;
    int IntVal;
}

%token <Str> ID TYPE
%token CLASS RETURN BGIN END ASSIGN NR

%%

progr: BGIN global_scope END{
    cout << "Am gasit un program: " << endl;
};

global_scope: decl;

decl: TYPE ID ';' {
        cout << "Declaratie variabila de tip " << *$1 << " cu numele " << *$2 << endl;
        delete $1;
        delete $2;
    }
    | TYPE ID '(' list_param ')' ';' {
        cout << "Declaratie functie de tip " << *$1 << " cu numele " << *$2 << endl;
        delete $1;
        delete $2;
    }
;

list_param: param
    | list_param ',' param
    ;

param: TYPE ID {
        cout << "Parametru de tip " << *$1 << " cu numele " << *$2 << endl;
        delete $1;
        delete $2;
    };
%%

void yyerror(const char* s) {
    cerr << "Error: " << s << endl;
}

int main(int argc, char** argv) {
    if(argc > 1) {
        yyin = fopen(argv[1], "r");
        if(!yyin) {
            cerr << "Nu pot deschide fisierul " << argv[1] << endl;
            return 1;
        }
    }

    // yyparse() este functia magica. Ea cheama yylex() in spate.
    yyparse(); 

    return 0;
}