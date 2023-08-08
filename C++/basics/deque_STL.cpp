//
// Created by 김지민 on 2023/08/08.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    deque<int> dq;
    dq.push_front(10); // 10
    dq.push_back(50); // 10 50
    dq.push_front(24); // 24 10 50
    for (int e: dq) cout << e << " "; // 24 10 50
    cout << "\n";
    cout << "size " << dq.size() << "\n"; // 3
    if (dq.empty()) cout << "dq is empty \n";
    else cout << "dq is not empty \n";
    dq.pop_front(); // 10 50
    dq.pop_back(); // 10
    cout << dq.back() << "\n"; // 10
    dq.push_back(72); // 10 72
    cout << dq.front() << "\n"; // 10
    dq.push_back(12); // 10 72 12
    dq[2] = 17; // 10 72 17
    dq.insert(dq.begin() + 1, 33); // 10 33 72 17
    dq.insert(dq.begin() + 4, 60); // 10 33 72 17 60
    for (int e: dq) cout << e << " "; // 10 33 72 17 60
    cout << "\n";
    dq.erase(dq.begin() + 3); // 10 33 72 60
    cout << dq[3] << "\n"; // 60
    dq.clear();
}

/*
 * "both vector and deque provide very similar interfaces"
 * push_front가 O(1) 안에 가능한 vector 느낌
 * insert, erase
 *
 * 하지만 vector와 다르게 메모리 구조가 연속적으로 되어 있진 않다.
 */