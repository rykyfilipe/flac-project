#pragma once
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class IdInfo {
public:
    string type;
    string name;
    string category; // "variable", "function", "class", "param"
    string value;    // Pentru variabile (opțional, dacă e constantă)
    vector<string> paramTypes; // Doar pentru funcții

    IdInfo() {}
    IdInfo(string type, string name, string category, string value = "") 
        : type(type), name(name), category(category), value(value) {}
};

class SymTable {
    SymTable* parent;
    map<string, IdInfo> ids;
    string scopeName; // Numele scopului (ex: "Global", "Main", "Function X")

public:
    SymTable(string name, SymTable* parent = NULL);
    
    // Verifică dacă există (recursiv în părinți pentru utilizare)
    bool existsId(string s);
    
    // Adaugă simbol în tabelul curent
    void addSymbol(string type, string name, string category, string value = "");
    
    // Adaugă info despre parametri (pentru funcții)
    void addFuncParam(string funcName, string paramType);

    // Printează tabelul curent în fișier
    void printTable(ofstream& out);

    SymTable* getParent();
    ~SymTable();
};