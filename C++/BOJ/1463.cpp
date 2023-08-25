//
// Created by 김지민 on 2023/08/25.
//
#include <bits/stdc++.h>
using namespace std;

int dp[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        dp[i] = 1 + dp[i - 1];
        if (i % 3 == 0) {
            dp[i] = min(dp[i], 1 + dp[i / 3]);
        }
        if (i % 2 == 0) {
            dp[i] = min(dp[i], 1 + dp[i / 2]);
        }
    }
    cout << dp[n];
}