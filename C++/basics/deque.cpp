//
// Created by 김지민 on 2023/08/08.
//

/*
 * deque: Double Ended Queue
 * stack + queue
 * STL deque: index로의 접근 가능
 */
#include <bits/stdc++.h>
using namespace std;

const int MX = 100005;
int dat[2 * MX + 1];
int head = MX, tail = MX;

void push_front(int x) {
    dat[--head] = x;
}

void push_back(int x) {
    dat[tail++] = x;
}

void pop_front() {
    head++;
}

void pop_back() {
    tail--;
}

int front() {
    return dat[head];
}

int back() {
    return dat[tail - 1];
}

void test() {
    push_front(1);
    push_back(2);
    push_front(3);
    cout << "front " << front() << "\n";
    cout << "back " << back() << "\n";
    pop_front();
    cout << "front " << front() << "\n";
    pop_back();
    cout << "back " << back() << "\n";
}

int main(void) {
    test();
}