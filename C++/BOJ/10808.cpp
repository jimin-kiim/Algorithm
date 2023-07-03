//
// Created by 김지민 on 2023/07/03.
//

#include <bits/stdc++.h>
using namespace std;

int frequency[26]; // declared in global scope -> automatically filled with zeros

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    for (char c : s) {
        frequency[c - 'a'] += 1;
    }

    for (int e : frequency) {
        cout << e << ' ';
    }
}