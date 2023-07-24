//
// Created by 김지민 on 2023/07/24.
//
#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX];
int pos = 0;

void push(int x) {
    dat[pos++] = x;
}

void pop() {
    pos--;
}

int top() {
    return dat[pos - 1];
}

void test() {
    push(2);
    push(5);
    push(10);
    pop();
    cout << top();
}

int main(void) {
    test();
}

/*
 * STL stack:
 * stack<int> s
 * push, pop, top, empty, size
 *
 * using 'pop' or 'top' when the stack is empty -> run time error
 */