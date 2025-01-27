#include <iostream>
#include <string>

using namespace std;

bool isDigitOrLower(char ch) {
    return (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z');
}

bool isDigitOrUpperOrLower(char ch) {
    return (ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

int main() {
    string input;
    bool rule2Active = false;

    while (true) {
        cout << "Enter input '#' or '##': ";
        cin >> input;

        if (input == "#") {
            cout << "RULE1 activated. Identifying only digits and lowercase letters." << endl;
            while (true) {
                cout << "Enter text (or '#' to exit RULE1): ";
                cin >> input;
                if (input == "#") {
                    break;
                }
                bool hasDigits = false;
                bool hasLowercaseLetters = false;
                for (char ch : input) {
                    if (isDigitOrLower(ch)) {
                        if (isdigit(ch)) {
                            hasDigits = true;
                        }
                        if (islower(ch)) {
                            hasLowercaseLetters = true;
                        }
                    }
                }
                if (hasDigits) {
                    cout << "Contains digits ";
                }
                if (hasLowercaseLetters) {
                    cout << "Contains lowercase letters ";
                }
                if (!hasDigits && !hasLowercaseLetters) {
                    cout << "No action executed ";
                }
                cout << endl;
            }
        } else if (input == "##") {
            if (rule2Active) {
                cout << "Exiting from ## start condition" << endl;
                break;
            }
            rule2Active = true;
            cout << "RULE2 activated. Identifying digits, uppercase, and lowercase letters." << endl;
            while (true) {
                cout << "Enter text (or '##' to exit RULE2): ";
                cin >> input;
                if (input == "##") {
                    cout << "Exiting from ## start condition" << endl;
                    break;
                }
                bool hasDigits = false;
                bool hasLowercaseLetters = false;
                bool hasUppercaseLetters = false;
                for (char ch : input) {
                    if (isDigitOrUpperOrLower(ch)) {
                        if (isdigit(ch)) {
                            hasDigits = true;
                        }
                        if (islower(ch)) {
                            hasLowercaseLetters = true;
                        }
                        if (isupper(ch)) {
                            hasUppercaseLetters = true;
                        }
                    }
                }
                if (hasDigits) {
                    cout << "Contains digits ";
                }
                if (hasLowercaseLetters) {
                    cout << "Contains lowercase letters ";
                }
                if (hasUppercaseLetters) {
                    cout << "Contains uppercase letters ";
                }
                if (!hasDigits && !hasLowercaseLetters && !hasUppercaseLetters) {
                    cout << "No action executed ";
                }
                cout << endl;
            }
        } else {
            cout << "Invalid input. Please enter '#' or '##'." << endl;
        }
    }

    return 0;
}
