//
// Created by 김지민 on 3/7/24.
//
#include <bits/stdc++.h>
using namespace std;

int n, m;
int res_indices[8];
int palette[8];
int is_used[8];

void func(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << palette[res_indices[i]] << " ";
        }
        cout << "\n";
        return;
    }

    int prev = 0;
    for (int i = 0; i < n; i++) {
        if (is_used[i] != 1 && prev != palette[i]) {
            res_indices[k] = i;
            prev = palette[i];
            is_used[i] = 1;
            func(k + 1);
            is_used[i] = 0;
        }
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
 * permutation,
 * possible numbers can be repeated,
 * but each of the numbers should be treated as different one,
 * the numbers should not be duplicated in a single permutation
 */