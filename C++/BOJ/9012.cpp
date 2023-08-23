//
// Created by 김지민 on 2023/08/23.
//
#include <bits/stdc++.h>
using namespace std;

bool verify(const string& a) {
    stack<char> s;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '(') {
            s.push('(');
        } else {
            if (!s.empty() && s.top() == '(') {
                s.pop();
            } else {
                return false;
            }
        }
    }
    if (!s.empty()) {
        return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    string input;
    while (n--) {
        cin >> input;
        bool result = verify(input);
        if (result) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}