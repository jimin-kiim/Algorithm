//
// Created by 김지민 on 1/19/24.
//
#include <bits/stdc++.h>
using namespace std;

char board[2190][2190]; // 3 ^ 7

void recursive_function(int x, int y, int size);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) fill(board[i], board[i] + n, ' ');

    recursive_function(0,  0, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j];
        }
        cout << "\n";
    }
}

void recursive_function(int x, int y, int size) {
    if ((x / size) % 3 == 1 && (y / size) % 3 == 1) return; // 로직 적용 예외 조건
    if (size == 1) { // 최소 단위에 도달했을 때의 로직 (종료 조건)
        board[x][y] = '*';
        return;
    }

    // 최소 단위에 도달하기 위해 재귀적으로 크기를 줄여나가는 로직
    size /= 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            recursive_function(x + size * i, y + size * j, size);
        }
    }
}