//
// Created by 김지민 on 1/15/24.
//

#include <bits/stdc++.h>
using namespace std;

void recursive_function(int row, int col, int size);
int n;
int arr[2188][2188];
// 3 ^ 7
int result[3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    recursive_function(0, 0, n);
    cout << result[0] << "\n" << result[1] << "\n" << result[2];
}

void recursive_function(int row, int col, int size) {
    if (size == 1) {
        int val = arr[row][col];
        result[val + 1]++;
        return;
    }
    bool flag = true;
    size = size / 3;
    if (arr[row][col + size] != arr[row][col + size - 1] || arr[row][col + size * 2] != arr[row][col + size * 2 - 1]) {
        for (int i = 0;  i < 3; i++) recursive_function(row, col + size * i, size);
        flag = false;
    }
    if (arr[row + size][col] != arr[row + size - 1][col] || arr[row + size * 2][col] != arr[row + size * 2 - 1][col]) {
        for (int i = 0;  i < 3; i++) recursive_function(row  + size * i, col, size);
        flag = false;
    }
    if (flag) {
        int val = arr[row][col];
        result[val + 1]++;
        return;
    }
}

/*
 * 같은 행에서 열을 옮기며 보다가 다른 수가 나오면 n / 3해서 탐색
 * n이 1이면 + 1
 *
 * 같은 행에서 열을 옮기며 보다가 다른 수가 안 나오면 그대로 1
 *
 * if (arr[0][n / 3] != arr[0][n / 3 - 1])
 *
 */