%{
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

#include "limbaj.tab.h"
%}

%option noyywrap
%option yylineno


%%

"int"|"float"|"string"|"bool" {
    yylval.Str = new std::string(yytext);
    return TYPE;
}
"new"          {return NEW; }
"print"        { return PRINT; }
"class"        { return CLASS; }
"return"       { return RETURN; }
"begin_progr"  { return BGIN; }
"end_progr"    { return END; }
"if"           { return IF; }
"else"         { return ELSE; }
"while"        { return WHILE; }
"for"          { return FOR; }

"=="|"!="|"<="|">="|"<"|">" { return CMP; }
"="            { return ASSIGN; }

"true" {
    yylval.BoolVal = true;
    return BVAL;
}
"false" {
    yylval.BoolVal = false;
    return BVAL;
}

[0-9]+\.[0-9]+ {
    yylval.FloatVal = atof(yytext);
    return FNR;
}

[0-9]+ {
    yylval.IntVal = atoi(yytext);
    return NR;
}

\"[a-zA-Z0-9 ]*\" {
    std::string temp(yytext);
    yylval.Str = new std::string(temp.substr(1, temp.size() - 2));
    return STRING;
}

[a-zA-Z][a-zA-Z0-9]* {
    yylval.Str = new std::string(yytext);
    return ID;
}

[ \t\n]+   { /* ignore */ }

.          { return yytext[0]; }

%%
