//
// Created by 김지민 on 3/6/24.
//
#include <bits/stdc++.h>
using namespace std;

int n, m;
int res_indices[8];
int palette[8];
int is_used[8];

void func(int start, int k) {
    // termination condition
    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << palette[res_indices[i]] << " ";
        }
        cout << "\n";
        return;
    }

    // start creating a new sequence
    for (int i = start; i < n; i++) {
        // promising function
        if (is_used[i] != 1) {
            // building a solution
            res_indices[k] = i;
            is_used[i] = 1;
            // recurrence
            func(i + 1, k + 1);
            // backtracking
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
 * combination, duplication of possible numbers not allowed, ascending order
 */