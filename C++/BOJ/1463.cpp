//
// Created by 김지민 on 2023/08/25.
//
#include <bits/stdc++.h>
using namespace std;

int dp[1000001];
#define MAX 9999;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        int a = MAX;
        int b = MAX;
        int c;
        if (i % 3 == 0) {
            a = 1 + dp[i / 3];
        }
        if (i % 2 == 0) {
            b = 1 + dp[i / 2];
        }
        c = 1 + dp[i - 1];
        int min_val = min(a, b);
        dp[i] = min(min_val, c);
    }
    cout << dp[n];
}