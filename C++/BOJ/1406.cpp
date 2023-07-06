//
// Created by 김지민 on 2023/07/05.
//
#include <bits/stdc++.h>
using namespace std;
// n : 600,000 -> large -> using list instead of array
int main() {
    string input;
    cin >> input;
    list<char> L = {};
    for (char e: input) {
        L.push_back(e);
    }
    int n;
    cin >> n;
    list<char>::iterator t = L.end();
    while(n--) {
        char command, data;
        cin >> command;
        if (command == 'L' && t != L.begin()) t--;
        else if (command == 'D' && t != L.end()) t++;
        else if (command == 'B' && t != L.begin()) t = L.erase(--t);
        else if (command == 'P'){
            cin >> data;
            L.insert(t, data);
        }
    }
    for (auto e: L) {
        cout << e;
    }
}