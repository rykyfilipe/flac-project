%{
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

#include "limbaj.tab.h" 
%}

%option noyywrap

%% 
"int"|"float"|"string"|"bool" { 
    yylval.Str = new std::string(yytext);
    cout << "TYPE : " << yytext << endl; 
    return TYPE; 
}
"class" { 
    cout << "CLASS" << endl;
    return CLASS; 
}
"return" { 
    cout << "RETURN" << endl; 
    return RETURN;
}
"begin_progr" { 
    cout << "BEGIN_PROGRAM" << endl;
    return BGIN; 
}
"end_progr" {
    cout << "END_PROGRAM" << endl;
    return END; 
}
"=" { 
    cout << "ASSIGN" << endl;
    return ASSIGN;
}
[a-zA-Z][a-zA-Z0-9]* { 
    yylval.Str = new std::string(yytext);
    cout << "ID : " << yytext << endl;
    return ID; 
}
[0-9]+ {
    yylval.IntVal = atoi(yytext); 
    cout << "NR : " << yytext << endl;    
    return NR;
}
[ \t\n]+        { /* ignora spatii */ }
.               { return yytext[0];}
