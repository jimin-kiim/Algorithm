//
// Created by 김지민 on 1/15/24.
//

#include <bits/stdc++.h>
using namespace std;

void recursive_function(int row, int col, int size);
int n;
int arr[2188][2188]; // 3 ^ 7
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

bool is_single_page(int x, int y, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (arr[x][y] != arr[x + i][y + j]) return false;
        }
    }
    return true;
}

void recursive_function(int x, int y, int size) {
    bool isSinglePage = is_single_page(x, y, size);
    if (isSinglePage == true) {
        int val = arr[x][y];
        result[val + 1]++;
//        cout << val << " " << result[val + 1] << "\n";
        return;
    }

    size /= 3;
    for (int i = 0;  i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            recursive_function(x + size * i, y + size * j, size);
        }
    }
}

/*
 * 같은 행에서 열을 옮기며 보다가 다른 수가 나오면 n / 3해서 탐색
 * n이 1이면 + 1
 *
 * 같은 행에서 열을 옮기며 보다가 다른 수가 안 나오면 그대로 1
 *
 * if (arr[0][n / 3] != arr[0][n / 3 - 1])
 * -> 지름길 찾으려고 한 시도.
 * -> 에러.
 *
 * 내부가 모두 같은지 체크해서 모두 동일한 값이면 그 값인 페이지 개수 값 + 1
 * 아니면 size /= 3 해서 재귀.
 *
 */