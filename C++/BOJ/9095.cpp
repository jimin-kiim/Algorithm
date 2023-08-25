//
// Created by 김지민 on 2023/08/15.
//
#include <bits/stdc++.h>
using namespace std;

int dp[12];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (int i = 4; i <= 11; i++) {
        dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
    }

    int n;
    while (t--) {
        cin >> n;
        cout << dp[n] << "\n";
    }
}