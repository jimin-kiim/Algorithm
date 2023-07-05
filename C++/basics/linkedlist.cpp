//
// Created by 김지민 on 2023/07/05.
//
#include <bits/stdc++.h>
using namespace std;

// standard
struct NODE {
    struct NODE *prev, *next;
    int data;
};

// simplified version for PS (using arr)
/*
 * index 0: dummy node
 */
const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1; // addr for a new node to be placed

void traverse() {
    int cur = nxt[0];
    while (cur != -1) {
        cout << dat[cur] << ' ';
        cur = nxt[cur];
    }
    cout << "\n\n";
}

void insert(int addr, int num) {
    dat[unused] = num;
    nxt[unused] = nxt[addr];
    nxt[addr] = unused;
    pre[nxt[unused]] = unused;
    pre[unused] = addr;
    unused++;
}

void erase(int addr) {

}

int main() {
    fill(pre, pre + MX, -1);
    fill(nxt, nxt + MX, -1);

}