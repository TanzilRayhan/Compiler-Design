#include <bits/stdc++.h>
using namespace std;

unordered_map<char, vector<string>> productions = {
    {'S', {"AaB"}},
    {'A', {"b", "#"}},
    {'B', {"c", "#"}}
};

unordered_map<char, unordered_set<char>> firstSets;

void calculateFirstSets(char nonTerminal) {
    if (firstSets.find(nonTerminal) != firstSets.end()) {
        return;
    }

    unordered_set<char> firstSet;

    for (const string &production : productions[nonTerminal]) {
        for (char symbol : production) {
            if (islower(symbol) || symbol == '#') {
                firstSet.insert(symbol);
                if (symbol != '#') {
                    break;
                }
            } else if (isupper(symbol)) {
                calculateFirstSets(symbol);

                firstSet.insert(firstSets[symbol].begin(), firstSets[symbol].end());

                if (firstSets[symbol].find('#') == firstSets[symbol].end()) {
                    break;
                }
            }
        }
    }

    if (nonTerminal == 'S') {
        firstSet.erase('#');
    }

    firstSets[nonTerminal] = firstSet;
}

void displayFirstSets() {
    for (const auto &entry : firstSets) {
        cout << "First(" << entry.first << ") = { ";
        for (char terminal : entry.second) {
            cout << terminal << " ";
        }
        cout << "}" << endl;
    }
}

int main() {
    for (const auto &entry : productions) {
        calculateFirstSets(entry.first);
    }

    displayFirstSets();

    return 0;
}
