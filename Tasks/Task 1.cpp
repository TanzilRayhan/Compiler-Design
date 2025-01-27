#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool isValidIdentifierChar(char c) {
    return isalpha(c) && islower(c);
}

bool isCommentedLine(const string& line) {
    size_t pos = line.find("//");
    return pos != string::npos;
}

bool isInsideQuotes(const string& line, size_t position) {
    char quoteChar = line[position];
    int count = 0;
    for (int i = position - 1; i >= 0; --i) {
        if (line[i] == quoteChar && (i == 0 || line[i - 1] != '\\')) {
            count++;
        } else {
            break;
        }
    }
    return count % 2 == 1;
}

void printCommentedLine(const string& line, int lineCount) {
    if (isCommentedLine(line)) {
        cout << "Line " << lineCount << ": Commented Line - " << line << endl;
    }
}

void printIdentifiers(const string& line, int lineCount, const unordered_set<string>& reservedKeywords) {
    if (!isCommentedLine(line)) {
        size_t pos = 0;
        vector<string> identifiers;
        while ((pos = line.find_first_of("abcdefghijklmnopqrstuvwxyz", pos)) != string::npos) {
            string identifier;
            while (pos < line.length() && isValidIdentifierChar(line[pos]) && !isInsideQuotes(line, pos)) {
                identifier += line[pos];
                pos++;
            }

            if (!identifier.empty() && reservedKeywords.find(identifier) == reservedKeywords.end()) {
                identifiers.push_back(identifier);
            }
        }

        if (!identifiers.empty()) {
            cout << "Line " << lineCount << ": Identifiers - ";
            for (const string& identifier : identifiers) {
                cout << identifier;
                if (&identifier != &identifiers.back()) {
                    cout << ", ";
                }
            }
            cout << endl;
        }
    }
}

void printLiterals(const string& line, int lineCount) {
    if (!isCommentedLine(line)) {
        size_t pos = 0;
        while ((pos = line.find_first_of("\"'", pos)) != string::npos) {
            char delimiter = line[pos];
            pos++;
            string literal;
            while (pos < line.length() && line[pos] != delimiter) {
                literal += line[pos];
                pos++;
            }
            if (!literal.empty()) {
                cout << "Line " << lineCount << ": Literals - " << literal << endl;
            }
            if (pos < line.length() && line[pos] == delimiter) {
                pos++;
            }
        }
    }
}

int main() {
    string filename;
    cout << "Enter the input file: ";
    cin >> filename;

    unordered_set<string> reservedKeywords = {"int", "main", "cout", "return"};

    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Error opening the file." << endl;
        return 1;
    }

    int lineCount = 0;

    while (!inputFile.eof()) {
        string line;
        getline(inputFile, line);
        lineCount++;

        printCommentedLine(line, lineCount);
        printIdentifiers(line, lineCount, reservedKeywords);
        printLiterals(line, lineCount);
    }

    inputFile.close();

    return 0;
}
