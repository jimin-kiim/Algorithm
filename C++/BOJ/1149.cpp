//
// Created by 김지민 on 2/8/24.
//
#include <bits/stdc++.h>
using namespace std;

int cost[1001][3];
//int dp[1001];
int dp[1001][3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> cost[i][j];
        }
    }
//
//    dp[1] = *min_element(cost[1], cost[1] + 3);
//
//    for (int i = 2; i <= n; i++) {
//        for (int j = 0; j < 3; j++) {
//            dp[i] = min(cost[i][(j + 1) % 3], cost[i][(j + 2) % 3]) + cost[]
//        }
//    }
    for (int i = 0; i < 3; i++) {
        dp[0][i] = cost[0][i];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            dp[i][j] = min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) + cost[i][j];
        }
    }
    cout << *min_element(dp[n - 1], dp[n - 1] + 3);
}

/*
 * i - 1이 택한 색 인덱스가
 * 0 이면 1, 2
 * 1 이면 2, 0
 * 2 이면 0, 1
 */