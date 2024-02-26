//
// Created by 김지민 on 2/26/24.
//
#include <bits/stdc++.h>
using namespace std;

int res[8];
int n, m;

void func(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
        return;
    }

    int start = 1;
    for (int i = start; i <= n; i++) {
        res[k] = i;
        func(k + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    func(0);
}