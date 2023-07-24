//
// Created by 김지민 on 2023/07/24.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    list<int> people = {};
    for (int i = 1; i < n + 1; i++) {
        people.push_back(i);
    }

    list<int> output = {};
    auto t = people.begin();
    while (!people.empty()) {
        for (int i = 0; i < k - 1; i++) {
            if (t == people.end()) t = people.begin();
            t++;
            if (t == people.end()) t = people.begin();
        }
        output.push_back(*t);
        t = people.erase(t);
    }

    auto it = output.begin();
    cout << "<" << *it++;
    for (; it != output.end(); it++) cout << ", " << *it;
    cout << ">";
}