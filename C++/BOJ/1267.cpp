//
// Created by 김지민 on 2023/07/12.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int y = 0;
    int m = 0;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        y += 10 + input / 30 * 10;
        m += 15 + input / 60 * 15;
    }

    if (y < m) {
        cout << "Y " << y;
    } else if (y == m) {
        cout << "Y M " << m;
    } else {
        cout << "M " << m;
    }
}