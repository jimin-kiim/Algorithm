//
// Created by 김지민 on 2/7/24.
//
#include <bits/stdc++.h>
using namespace std;

int board[501][501];
int score[501][501];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    // init
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= i; j++) {
            cin >> board[i][j];
        }
    }

    score[1][1] = board[1][1];

    // dp
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {

            // 아래 층에 있는 수는 현재 층에서 선택된 수의 대각선 왼쪽 또는 대각선 오른쪽에 있는 것 중에서만 선택 가능 조건 반영
            score[i][j] = max(score[i - 1][j - 1], score[i - 1][j]) + board[i][j];
        }
    }

    // max_element: iterator 반환
    cout << *max_element(score[n] + 1, score[n] + n  + 1);
}