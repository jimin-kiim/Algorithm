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
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= i; j++) {
            cin >> board[i][j];
        }
    }
    score[1][1] = board[1][1];
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            score[i][j] = max(score[i - 1][j - 1], score[i - 1][j]) + board[i][j];
        }
    }
    cout << *max_element(score[n] + 1, score[n] + n  + 1);
}