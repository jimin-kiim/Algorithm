//
// Created by 김지민 on 3/6/24.
//
#include <bits/stdc++.h>
using namespace std;

int n, m;
int res[8];
int palette[8];
int start;

void func(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
        return;
    }

    int prev = start;
    start = 0;
    if (k != 0) start = prev + 1;
    for (int i = start; i < n; i++) {
        res[k] = palette[i];
        func(k + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> palette[i];
    }

    sort(palette, palette + n);

    func(0);
}

/*
 * combination, duplication of possible numbers not allowed, ascending order
 */