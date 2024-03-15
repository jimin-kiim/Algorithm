//
// Created by 김지민 on 3/15/24.
//
#include <bits/stdc++.h>
using namespace std;

int n;
int res[81];
int flag = 0;

void func(int k) {
    if (k == n) {
        for (int i = 0; i < n; i++) {
            cout << res[i];
        }
        cout << "\n";
        flag = 1;
        return;
    }

    for (int i = 1; i <= 3; i++) {
        if (k != 0 && res[k - 1] == i) continue;
        if (k >= 3 && res[k - 1] == res[k - 3] && res[k - 2] == i) continue;
        res[k] = i;
        func(k + 1);
        if (flag) return;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    func(0);
}
/*
 * - selecting n numbers.
 * - the number used right before should be skipped
 *
 */