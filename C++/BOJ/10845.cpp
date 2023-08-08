//
// Created by 김지민 on 2023/08/08.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios:: sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string command;
    int data;
    queue<int> q;
    while (n--) {
        cin >> command;
        if (command == "push") {
            cin >> data;
            q.push(data);
        } else if (command == "front") {
            if (q.empty()) cout << -1 << "\n";
            else cout << q.front() << "\n";
        } else if (command == "back") {
            if (q.empty()) cout << -1 << "\n";
            else cout << q.back() << "\n";
        } else if (command == "size") {
            cout << q.size() << "\n";
        } else if (command == "pop") {
            if (q.empty()) cout << -1 << "\n";
            else {
                cout << q.front() << "\n";
                q.pop();
            }
        } else if (command == "empty") {
            if (q.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
    }
}