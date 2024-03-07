//
// Created by 김지민 on 3/7/24.
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
    int start = 0;
    if (k != 0) start = res_indices[k - 1];
    for (int i = start; i < n; i++) {
        res_indices[k] = i;
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
 * combination(condition says that it's permutation but the numbers that make it up should not be in a descending order so it ends up being combination)
 * duplication of possible numbers is allowed,
 * combinations should be aligned in an ascending order
 */