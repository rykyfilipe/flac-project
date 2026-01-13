#include "SymTable.h"

SymTable::SymTable(string name, SymTable* parent) : scopeName(name), parent(parent) {}

void SymTable::addSymbol(string type, string name, string category, string value) {
    
    cout << "[DEBUG] Adding " << name << " to scope " << scopeName << endl;
    if (ids.count(name)) {
        // Opțional: Poți arunca eroare dacă redeclari variabila în același scope
        cout << "Warning: Symbol " << name << " already defined in " << scopeName << endl;
        return;
    }
    IdInfo info(type, name, category, value);
    ids[name] = info;
}

void SymTable::addFuncParam(string funcName, string paramType) {
    if (ids.count(funcName)) {
        ids[funcName].paramTypes.push_back(paramType);
    }
}

void SymTable::updateValue(string name, string newValue) {
    if (ids.count(name)) {
        ids[name].value = newValue;
    } else if (parent != NULL) {
        parent->updateValue(name, newValue);
    }
}

bool SymTable::existsId(string s) {
    // Caută local
    if (ids.count(s)) return true;
    // Caută în părinte (dacă există)
    if (parent != NULL) return parent->existsId(s);
    return false;
}

SymTable* SymTable::getParent() {
    return parent;
}

void SymTable::printTable(ofstream& out) {
    out << "=== Symbol Table: " << scopeName << " ===" << endl;
    if (parent) {
        out << "Parent Scope: " << parent->scopeName << endl;
    } else {
        out << "Parent Scope: NULL (Global)" << endl;
    }
    out << "--------------------------------------------------" << endl;
    out << "Name \t | Category \t | Type \t | Value/Params" << endl;
    out << "--------------------------------------------------" << endl;

    for (const auto& entry : ids) {
        IdInfo info = entry.second;
        out << info.name << " \t | " << info.category << " \t | " << info.type << " \t | ";
        
        if (info.category == "function") {
            out << "(";
            for (size_t i = 0; i < info.paramTypes.size(); ++i) {
                out << info.paramTypes[i] << (i < info.paramTypes.size() - 1 ? ", " : "");
            }
            out << ")";
        } else {
            out << info.value;
        }
        out << endl;
    }
    out << endl; // Linie goală între tabele
}

SymTable::~SymTable() {
    ids.clear();
}