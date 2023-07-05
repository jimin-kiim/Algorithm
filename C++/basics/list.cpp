//
// Created by 김지민 on 2023/07/05.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> L = {1, 2};
    list<int>:: iterator t = L.begin();
    L.push_front(10);
    cout << *t << '\n';
    L.push_back(5);
    L.insert(t, 6);
    t++;
    t = L.erase(t); // next one of the element t was pointing
    cout << *t << '\n';
    for (auto i : L) cout << i << ' ';
    cout << '\n';
    for (list<int>::iterator it = L.begin(); it != L.end(); it++) {
        cout << *it << ' ';
    }
}