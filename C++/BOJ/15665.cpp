//
// Created by 김지민 on 3/8/24.
//
#include <bits/stdc++.h>
using namespace std;

int n, m;
int res_indices[8];
int palette[8];

void func(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << palette[res_indices[i]] << " ";
        }
        cout << "\n";
        return;
    }

    int prev = 0;
    for (int i = 0; i < n; i++) { // descending order in a single permutation is allowed
        if (prev != palette[i]) { // the permutations should be unique
            res_indices[k] = i;
            prev = palette[i];
            func(k + 1);
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