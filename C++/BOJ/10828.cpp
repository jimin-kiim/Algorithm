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

    int stack[10001];
    int pos = 0;

    while (n--) {
        string command;
        int data;
        cin >> command;

        if (command == "push") {
            cin >> data;
            stack[pos++] = data;
        } else if (command == "top") {
            if (pos) cout << stack[pos - 1];
            else cout << -1;
            cout << "\n";
        } else if (command == "size") {
            cout << pos;
            cout << "\n";
        } else if (command == "pop") {
            if (pos) cout << stack[--pos];
            else cout << -1;
            cout << "\n";
        } else if (command == "empty") {
            if (pos) cout << 0;
            else cout << 1;
            cout << "\n";
        }
    }
}