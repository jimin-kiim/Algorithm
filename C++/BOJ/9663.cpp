//
// Created by 김지민 on 2023/08/30.
//
#include <bits/stdc++.h>
using namespace std;

int n;
int ans;
int q[16];

bool is_safe(int col, int row) {
    for (int i = 0; i < row; i++) {
        if (q[i] == col || col - q[i] == row - i || q[i] - col == row - i) return 0;
    }
    return 1;
}

void func(int row) {
    if (row == n) {
        ans++;
        return;
    }

    for (int col = 0; col < n; col++) {
        if (is_safe(col, row)) {
            q[row] = col;
            func(row + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    func(0);
    cout << ans;
}