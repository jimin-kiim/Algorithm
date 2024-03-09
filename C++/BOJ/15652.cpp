//
// Created by 김지민 on 2/26/24.
//
#include <bits/stdc++.h>
using namespace std;

int res[9];
int n, m;

void func(int start, int k) {
    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = start; i <= n; i++) {
        res[k] = i;
        func(i, k + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    func(1, 0);
}

/*
 * combination, duplication of possible numbers allowed, ascending order
 */