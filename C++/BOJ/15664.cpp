//
// Created by 김지민 on 3/8/24.
//
#include <bits/stdc++.h>
using namespace std;

int n, m;
int res_indices[8];
int palette[8];
int is_used[8];

void func(int start, int k) {
    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << palette[res_indices[i]] << " ";
        }
        cout << "\n";
        return;
    }

    int prev = 0; // consequential permutations should be unique
    for (int i = start; i < n; i++) {
        if (is_used[i] != 1 && prev != palette[i]) {
            res_indices[k] = i;
            prev = palette[i];
            is_used[i] = 1;
            func(i, k + 1);
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
    func(0, 0);
}
/*
 * combination(permutation but the additional condition says that the numbers in a single permutation should not be aligned in a descending order so it ends up to be combination, at last)
 *
 */