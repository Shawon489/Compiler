#include<bits/stdc++.h>
using namespace std;

map<string, string> rules;
string stk = "", input;

void reduce() {
    for (auto rule: rules) {
        if (stk.find(rule.first) != -1) {
            int position = stk.find(rule.first);
            stk.erase(position); // Remove the right side of the production
            stk += rule.second; // Add the left side of the production
            cout << left << setw(20) << "$" + stk << left << setw(15) << input + "$" << right << setw(10) << "REDUCE " << rule.second << "->" << rule.first << '\n';
            reduce();
        }
    }
}

int main() {
    freopen("10_input.txt", "r", stdin);

    // n = number od production rules
    int n; cin >> n;

    string production;
    cin.ignore();
    for (int i = 0; i < n; i++) { // Read the grammar
        getline(cin, production);
        // cout << production << '\n';
        // cout << production.substr(3) << ' ' << production[0] << '\n';
        rules[production.substr(3)] = production[0]; // Left side = production key, Right side = Value
    }

    getline(cin, input); // a+a*(a+a)+a

    cout << "Stack               Input               Action\n";
    cout << left << setw(20) << "$" + stk << right << setw(12) << input + "$" << '\n';

    while (!input.empty()) {
        stk += input[0]; // Push the terminal into stack
        input.erase(0, 1); // Remove the first character from input
        cout << left << setw(20) << "$" + stk << setw(15) << input + "$" << right << setw(10) << "SHIFT " << stk.back() << '\n';
        reduce();
    }

    if (stk == "E") cout << "ACCEPTED\n";
    else cout << "REJECTED\n";

    return 0;
}
