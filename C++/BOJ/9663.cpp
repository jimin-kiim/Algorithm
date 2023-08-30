//
// Created by 김지민 on 2023/08/30.
//
#include <bits/stdc++.h>
using namespace std;

int n;
int ans;
bool unavailable[16];
int q[16];

bool is_safe(int col, int row) {
    if (unavailable[col]) return 0;
    for (int i = 0; i < row; i++) {
        if (col - q[i] == row - i || q[i] - col == row - i) return 0;
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
            unavailable[col] = 1;
            q[row] = col;
            func(row + 1);
            unavailable[col] = 0;
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