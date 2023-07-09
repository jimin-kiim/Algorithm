//
// Created by 김지민 on 2023/07/06.
//
#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
char dat[MX];
int pre[MX], nxt[MX];
int unused = 1;

// inserting next to addr
void insert(int addr, int num) {
    dat[unused] = num;
    nxt[unused] = nxt[addr];
    pre[unused] = addr;
    if (nxt[addr] != -1) pre[nxt[addr]] = unused;
    nxt[addr] = unused;
    unused++;
}

void erase(int addr) {
    nxt[pre[addr]] = nxt[addr];
    if (nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
}

void traverse() {
    int current = nxt[0];
    while(current != -1) {
        cout << dat[current];
        current = nxt[current];
    }
}

int main() {
    fill(pre, pre + MX, -1);
    fill(nxt, nxt + MX, -1);

    string input;
    cin >> input;

    int cursor = 0;
    for (char c : input) {
        insert(cursor, c);
        cursor++;
    }

    int steps;
    cin >> steps;

    while(steps--) {
        char command, data;
        cin >> command;
        if (command == 'L' && pre[cursor] != -1) {
            cursor = pre[cursor];
        } else if (command == 'D' && nxt[cursor] != -1) {
            cursor = nxt[cursor];
        } else if (command == 'B' && pre[cursor] != -1) {
            erase(cursor);
            cursor = pre[cursor];
        } else if (command == 'P') {
            cin >> data;
            insert(cursor, data);
            cursor = nxt[cursor];
        }
    }
    traverse();
}