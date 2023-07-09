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
    nxt[addr] = unused;
    if (nxt[addr] != -1) pre[nxt[addr]] = unused;
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

    int endpoint = input.size() - 1;
//    int cursor = endpoint;

    while(steps--) {
        char command, data;
        cin >> command;
        if (command == 'L' && pre[cursor] != -1) {
            cursor = pre[cursor];
        } else if (command == 'D' && nxt[cursor] != -1) {
            cursor = nxt[cursor];
        } else if (command == 'B' && pre[cursor] != -1) {
            erase(pre[cursor]);
            cursor = pre[cursor];
//            nxt[pre[cursor]] = nxt[cursor];
//            pre[nxt[cursor]] = pre[cursor];
        } else if (command == 'P') {
            cin >> data;
            insert(pre[cursor], data);
            cursor = nxt[cursor];
//            dat[unused] = data;
//            nxt[unused] = cursor;
//            nxt[pre[cursor]] = unused;
//            if (cursor != unused) pre[nxt[cursor]] = unused;
//            pre[unused] = pre[cursor];
//            unused++;
        }
    }
//    int pointer = nxt[0];
//    while(pointer != -1) {
//        cout << dat[pointer];
//        pointer = nxt[pointer];
//    }
    traverse();
}