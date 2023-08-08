//
// Created by 김지민 on 2023/08/08.
//
#include <bits/stdc++.h>
using namespace std;

int dat[10001];
int head = 0, tail = 0;

int main() {
    ios:: sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string command;
    int data;

    while (n--) {
        cin >> command;
        if (command == "push") {
            cin >> data;
            dat[tail++] = data;
        } else if (command == "front") {
            if (head == tail) cout << -1 << "\n";
            else cout << dat[head] << "\n";
        } else if (command == "back") {
            if (head == tail) cout << -1 << "\n";
            else cout << dat[tail - 1] << "\n";
        } else if (command == "size") {
            cout << tail - head << "\n";
        } else if (command == "pop") {
            if (head == tail) cout << -1 << "\n";
            else cout << dat[head++] << "\n";
        } else if (command == "empty") {
            if (head == tail) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
    }
}