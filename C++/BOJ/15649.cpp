//
// Created by 김지민 on 2023/08/30.
//
#include <bits/stdc++.h>
using namespace std;

int n, m;
int sequence[9];
bool is_used[9];

void func(int k) {
    if (k == m) { // termination
        for (int i = 0; i < m; i++) cout << sequence[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = 1; i <= n; i++) { // recurrence
        if (!is_used[i]) {
            sequence[k] = i;
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
    func(0);
}