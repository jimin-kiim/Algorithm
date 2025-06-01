//
// Created by 김지민 on 2023/08/30.
//
#include <bits/stdc++.h>
using namespace std;
// permutation, combination => backtracking.
// backtracking - termination condition, creating a new sequence, promising function, building a solution, recurrence, backtracking
// if the element is not allowed to be duplicated, use 'is_used' array.

int n, m;
int sequence[9];
bool is_used[9]; // duplicate of usage is not allowed.

void func(int k) {
    // termination condition
    if (k == m) {
        for (int i = 0; i < m; i++) cout << sequence[i] << " ";
        cout << "\n";
        return;
    }

    // selecting subsequent elements
    for (int i = 1; i <= n; i++) {
        // promising function
        if (!is_used[i]) {
            // building a solution
            sequence[k] = i;
            is_used[i] = 1;
            // recurrence
            func(k + 1);
            // backtracking
            is_used[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    func(0);
}