//
// Created by 김지민 on 2023/07/04.
//


#include <bits/stdc++.h>
using namespace std;

int frequency[10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c, d;
    cin >> a;
    cin >> b;
    cin >> c;
    d = a * b * c;
    string result = to_string(d);

    for (char c : result) {
        frequency[c-'0'] += 1;
    }
    for (int i = 0; i < 10; i++) {
        cout << frequency[i] << "\n";
    }
}