//
// Created by 김지민 on 2023/08/31.
//
#include <bits/stdc++.h>
using namespace std;

int n;
int ans;
bool upper[16];
bool left_diag[30];
bool right_diag[30];

void func(int row) {
    if (row == n) {
        ans++;
        return;
    }

    for (int col = 0; col < n; col++) {
        if (!upper[col] && !right_diag[col + row] && !left_diag[col - row + n - 1]) {
            upper[col] = 1;
            right_diag[col + row] = 1;
            left_diag[col - row + n - 1] = 1;
            func(row + 1);
            upper[col] = 0;
            right_diag[col + row] = 0;
            left_diag[col - row + n - 1] = 0;
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