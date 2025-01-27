#include <iostream>
#include <string>

using namespace std;

bool isValidIdentifierChar(char c) {
    return isalpha(c) || c == '_';
}

bool isValidFunctionDeclaration(const string& declaration) {
    size_t pos = 0;
    while (pos < declaration.length() && declaration[pos] == ' ') {
        pos++;
    }
    if (pos < declaration.length() && isValidIdentifierChar(declaration[pos])) {
        pos++;
        while (pos < declaration.length() && (isValidIdentifierChar(declaration[pos]) || isspace(declaration[pos]))) {
            pos++;
        }
        while (pos < declaration.length() && isspace(declaration[pos])) {
            pos++;
        }
        return pos == declaration.length() || declaration[pos] == ';';
    }
    return false;
}

bool isValidFunctionDefinition(const string& definition) {
    size_t pos = 0;
    while (pos < definition.length() && definition[pos] == ' ') {
        pos++;
    }
    if (pos < definition.length() && isValidIdentifierChar(definition[pos])) {
        pos++;
        while (pos < definition.length() && isValidIdentifierChar(definition[pos])) {
            pos++;
        }
        while (pos < definition.length() && isspace(definition[pos])) {
            pos++;
        }
        return pos < definition.length() && definition[pos] == '(';
    }
    return false;
}

int main() {
    string declaration, definition;

    cout << "Enter a function declaration: ";
    getline(cin, declaration);

    if (isValidFunctionDeclaration(declaration)) {
        cout << "Valid function declaration." << endl;
    } else {
        cout << "Invalid function declaration." << endl;
    }

    cout << "Enter a function definition: ";
    getline(cin, definition);

    if (isValidFunctionDefinition(definition)) {
        cout << "Valid function definition." << endl;
    } else {
        cout << "Invalid function definition." << endl;
    }

    return 0;
}
