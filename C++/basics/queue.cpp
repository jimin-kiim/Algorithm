//
// Created by 김지민 on 2023/08/08.
//
#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX];
int head = 0, tail = 0;

void push(int x) {
    dat[tail++] = x;
}

void pop() {
    head++;
}

int front() {
    return dat[head];
}

int back() {
    return dat[tail - 1];
}

void test() {
    push(5);
    push(10);
    cout << front() << "\n";
    pop();
    cout << front() << "\n";
    cout << back() << "\n";
}

int main() {
    test();
}