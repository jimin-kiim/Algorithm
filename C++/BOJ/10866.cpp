//
// Created by 김지민 on 2023/08/08.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string command;
    int data;

    deque<int> dq;
    while (n--) {
        cin >> command;
        if (command == "push_front") {
            cin >> data;
            dq.push_front(data);
        } else if (command == "push_back") {
            cin >> data;
            dq.push_back(data);
        } else if (command == "pop_front") {
            if (dq.empty()) cout << -1 << "\n";
            else {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
        } else if (command == "pop_back") {
            if (dq.empty()) cout << -1 << "\n";
            else {
                cout << dq.back() << "\n";
                dq.pop_back();
            }
        } else if (command == "size") {
            cout << dq.size() << "\n";
        } else if (command == "empty") {
            if (dq.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        } else if (command == "front") {
            if (dq.empty()) cout << -1 << "\n";
            else cout << dq.front() << "\n";
        } else if (command == "back") {
            if (dq.empty()) cout << -1 << "\n";
            else cout << dq.back() << "\n";
        }
    }
}