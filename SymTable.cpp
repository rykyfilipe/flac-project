#include "SymTable.h"

map<string, ClassDefinition> SymTable::classRegistry;

SymTable::SymTable(string name, SymTable* parent) : scopeName(name), parent(parent) {}

bool SymTable::existsIdLocal(string s) {
    return ids.count(s) > 0;
}

bool SymTable::addSymbol(string type, string name, string category, string value) {
    if (existsIdLocal(name)) return false; 
    
    IdInfo info(type, name, category, value);
    ids[name] = info;

    if (scopeName.find("Class: ") == 0) {
        string className = scopeName.substr(7);
        SymTable::classRegistry[className].members[name] = info;
    }
    return true;
}

void SymTable::addFuncParam(string funcName, string paramType) {
    if (ids.count(funcName)) {
        ids[funcName].paramTypes.push_back(paramType);
    }
}

string SymTable::getType(string name) {
    if (ids.count(name)) return ids[name].type;
    if (parent) return parent->getType(name);
    return "";
}

IdInfo* SymTable::getSymbolInfo(string name) {
    if (ids.count(name)) return &ids[name];
    if (parent) return parent->getSymbolInfo(name);
    return nullptr;
}

void SymTable::updateValue(string name, string newValue) {
    if (ids.count(name)) ids[name].value = newValue;
    else if (parent) parent->updateValue(name, newValue);
}

bool SymTable::existsId(string s) {
    if (ids.count(s)) return true;
    if (parent != NULL) return parent->existsId(s);
    return false;
}

SymTable* SymTable::getParent() { return parent; }

void SymTable::printTable(ofstream& out) {
    out << "=== Symbol Table: " << scopeName << " ===" << endl;
    out << "Name \t | Category \t | Type \t | Value/Params" << endl;
    out << "--------------------------------------------------" << endl;
    for (const auto& entry : ids) {
        IdInfo info = entry.second;
        out << info.name << " \t | " << info.category << " \t | " << info.type << " \t | ";
        if (info.category == "function" || info.category == "constructor") {
            out << "(";
            for (size_t i = 0; i < info.paramTypes.size(); ++i)
                out << info.paramTypes[i] << (i < info.paramTypes.size() - 1 ? ", " : "");
            out << ")";
        } else out << info.value;
        out << endl;
    }
    out << endl;
}

SymTable::~SymTable() { ids.clear(); }