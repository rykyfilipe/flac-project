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
    return TYPE; 
}
"class" { 
    return CLASS; 
}
"return" { 
    return RETURN;
}
"begin_progr" { 
    return BGIN; 
}
"end_progr" {
    return END; 
}
"=" { 
    return ASSIGN;
}
[0-9]+\.[0-9]+ { yylval.FloatVal = atof(yytext); return FNR; }
"if"         { return IF; }
"else"       { return ELSE; }
"while"      { return WHILE; }
"for"        { return FOR; }
"true"       { yylval.IntVal = 1; return BVAL; }
"false"      { yylval.IntVal = 0; return BVAL; }
[a-zA-Z][a-zA-Z0-9]* { 
    yylval.Str = new std::string(yytext);
    return ID; 
}
[0-9]+ {
    yylval.IntVal = atoi(yytext); 
    return NR;
}
"=="|"!="|"<"|">"|"<="|">=" { return CMP; }

\"[a-zA-Z0-9 ]*\" {
    std::string temp(yytext);
    yylval.Str = new std::string(temp.substr(1, temp.size() - 2)); 
    return STRING;
}
[ \t\n]+        { /* ignora spatii */ }

.               { return yytext[0];}
