#include <iostream>
#include <string>

using namespace std;

bool isAlphabets(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

bool isValidVariableChar(char c) {
    return isAlphabets(c) || isDigit(c) || c == '_';
}

bool isValidVariable(const string& variable) {
    if (variable.empty() || isDigit(variable[0])) {
        return false;  // Variable can't start with a digit
    }

    for (char c : variable) {
        if (!isValidVariableChar(c)) {
            return false;  // Invalid character in variable
        }
    }

    return true;
}

bool isProperlyParenthesized(const string& expression) {
    int balance = 0;
    for (char c : expression) {
        if (c == '(') {
            balance++;
        } else if (c == ')') {
            balance--;
            if (balance < 0) {
                return false;  // More closing parentheses than opening ones
            }
        }
    }
    return balance == 0;  // Parentheses are properly balanced if balance is 0
}

int main() {
    string variable;
    cout << "Enter a variable: ";
    cin >> variable;

    if (isValidVariable(variable)) {
        cout << "Variable '" << variable << "' is properly declared." << endl;
    } else {
        cout << "Invalid variable declaration." << endl;
    }

    string expression;
    cout << "Enter a mathematical expression: ";
    cin.ignore();  // Clear the newline character from the buffer
    getline(cin, expression);

    if (isProperlyParenthesized(expression)) {
        cout << "The expression is properly parenthesized." << endl;
    } else {
        cout << "The expression is NOT properly parenthesized." << endl;
    }

    return 0;
}
