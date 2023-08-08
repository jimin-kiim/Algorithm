//
// Created by 김지민 on 2023/08/08.
//
#include <bits/stdc++.h>
using namespace std;

//int MX = 10000;
int dat[2*10000 + 1];
int head = 10000, tail = 10000;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string command;
    int data;

    while (n--) {
        cin >> command;
        if (command == "push_front") {
            cin >> data;
            dat[--head] = data;
        } else if (command == "push_back") {
            cin >> data;
            dat[tail++] = data;
        } else if (command == "pop_front") {
            if (head == tail) cout << -1 << "\n";
            else {
                cout << dat[head++] << "\n";
            }
        } else if (command == "pop_back") {
            if (head == tail) cout << -1 << "\n";
            else {
                cout << dat[tail - 1] << "\n";
                tail--;
            }
        } else if (command == "size") {
            cout << tail- head << "\n";
        } else if (command == "empty") {
            if (head == tail) cout << 1 << "\n";
            else cout << 0 << "\n";
        } else if (command == "front") {
            if (head == tail) cout << -1 << "\n";
            else cout << dat[head] << "\n";
        } else if (command == "back") {
            if (head == tail) cout << -1 << "\n";
            else cout << dat[tail - 1] << "\n";
        }
    }
}