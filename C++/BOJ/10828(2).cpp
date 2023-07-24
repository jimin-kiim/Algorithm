//
// Created by 김지민 on 2023/07/24.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    stack<int> s;

    while (n--) {
        string command;
        int data;
        cin >> command;

        if (command == "push") {
            cin >> data;
            s.push(data);
        } else if (command == "pop") {
            if (s.empty()) cout << -1 << "\n";
            else {
                cout << s.top() << "\n";
                s.pop();
            }
        } else if (command == "size") {
            cout << s.size() << "\n";
        } else if (command == "empty") {
            cout << (int) s.empty() << "\n";
        } else if (command == "top") {
            if (s.empty()) cout << -1 << "\n";
            else cout << s.top() << "\n";
        }
    }
}