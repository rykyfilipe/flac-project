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
    string category; // "variable", "function", "class", "param", "object", "constructor"
    string value;
    vector<string> paramTypes;

    IdInfo() {}
    IdInfo(string type, string name, string category, string value = "") 
        : type(type), name(name), category(category), value(value) {}
};

struct ClassDefinition {
    string className;
    map<string, IdInfo> members;
};

class SymTable {
    SymTable* parent;
    map<string, IdInfo> ids;
    string scopeName;

public:
    static map<string, ClassDefinition> classRegistry;

    SymTable(string name, SymTable* parent = NULL);
    bool existsId(string s);
    bool existsIdLocal(string s); 
    bool addSymbol(string type, string name, string category, string value = "");
    string getType(string name);
    IdInfo* getSymbolInfo(string name);
    void addFuncParam(string funcName, string paramType);
    void updateValue(string name, string newValue);
    void printTable(ofstream& out);
    SymTable* getParent();
    string getScopeName() { return scopeName; }
    ~SymTable();
};