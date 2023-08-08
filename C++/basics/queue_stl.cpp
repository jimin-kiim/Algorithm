//
// Created by 김지민 on 2023/08/08.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout << q.size() << "\n";
    if (q.empty()) cout << "q is empty\n";
    else cout << "q is not empty\n";
    q.pop();
    cout << q.front() << "\n";
    cout << q.back() << "\n";
    q.push(40);
    q.pop();
    cout << q.front() << "\n";
}
/*
 * BFS, Flood Fill 
 */