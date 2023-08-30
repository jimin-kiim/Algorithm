//
// Created by 김지민 on 2023/08/15.
//
#include <bits/stdc++.h>
using namespace std;

int k;
int result[6];
int palette[14];

void func(int n, int cur) {
    if (n == 6) {
        for (int i = 0; i < 6; i++) cout << result[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = cur; i < k; i++) {
            result[n] = palette[i];
            func(n + 1, i + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1) {
        cin >> k;
        if (k == 0) break;

        for (int i = 0; i < k; i++) cin >> palette[i];
        func(0, 0);
        cout << "\n";
    }
}