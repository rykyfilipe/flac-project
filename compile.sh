#!/bin/bash

rm -f lex.yy.c
rm -f limbaj.tab.c
rm -f limbaj.tab.h
rm -f program.exe

bison -d limbaj.y
flex limbaj.l
g++ lex.yy.c limbaj.tab.c -o program.exe
./program.exe