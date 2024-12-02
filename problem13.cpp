#include<bits/stdc++.h>
using namespace std;

bool isInteger(string s) {
    for (auto x: s) {
        if (x < '0' || x > '9') return false;
    }
    return true;
}

bool isValidIdentifier(string s) {
    // cout << s << "= ";
    if (s.size() == 0 || (!isalpha(s[0]) && s[0] != '_')) return false;
    for (auto ch: s) {
        if (!isalnum(ch) && ch != '_') return false;
    }
    vector<string> keywords = {
        "alignas", "alignof", "and", "and_eq", "asm", "auto", "bitand", "bitor", "while", "xor"
    };
    if (find(keywords.begin(), keywords.end(), s) != keywords.end()) return false;
    return true;
}

int32_t main() {
    string inp;
    while (getline(cin, inp)) {
        bool isValid = true;
        int operators = 0;
        vector<string> operands;
        string operand;
        stack<char> stk;
        for (char ch: inp) {
            if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
                if (operand.size()) operands.push_back(operand);
                operand = "";
                operators++;
            }
            else {
                if (ch == '(') {
                    if (operand.size()) { // a(b+c) = invalid
                        isValid = false;
                        break;
                    }
                    stk.push(ch);
                }
                else if (ch == ')') {
                    if (!stk.empty() && operand.size()) {
                        stk.pop();
                    }
                    else {
                        isValid = false;
                        break;
                    }
                }
                else {
                    operand += ch;
                }
            }
        }

        if (operand.size()) operands.push_back(operand);

        for (auto operand: operands) {
            if (!isInteger(operand) && !isValidIdentifier(operand)) {
                isValid = false;
                break;
            }
        }
        // cout << operands.size() << ' ' << operators << "= ";

        if (isValid && operands.size() == operators + 1 && stk.empty()) {
            cout << inp << ": Valid\n";
        }
        else cout << inp << ": Invalid\n";
    }
    return 0;
}
