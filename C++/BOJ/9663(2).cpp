//
// Created by 김지민 on 2023/08/31.
//
#include <bits/stdc++.h>
using namespace std;

int n;
int ans;
bool upper[16]; // treating the column values as a 1 dimensional positions.
bool left_diag[30]; // treating the left_diagonal values as a 1 dimensional positions; whose index value is the result of the sum of row + col. (calculated by solving equations)
bool right_diag[30]; // treating the right_diagonal values as a 1 dimensional positions; whose index value is the result of the row - col + n - 1. (calculated by resolving the equations)

void func(int row) {
    // termination condition
    if (row == n) {
        ans++;
        return;
    }

    for (int col = 0; col < n; col++) {
        // promising function - validation
        if (!upper[col] && !right_diag[col + row] && !left_diag[col - row + n - 1]) {
            // if it's valid, build a solution; remarking that a queen is positioned.
            upper[col] = 1;
            right_diag[col + row] = 1;
            left_diag[col - row + n - 1] = 1;
            // recurrence; moving forward to a further step.
            func(row + 1);
            // backtracking; removing a queen; undoing.
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