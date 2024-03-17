//
// Created by 김지민 on 3/17/24.
//
#include <bits/stdc++.h>
using namespace std;

long long dp[91]; // storing the number of all the possible cases. index == n

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n];
}

/*
 * dp[1]: 1 -> 1
 * dp[2]: 10 -> 1
 * dp[3]: 101: 10 + 1, 100: 10 + 0 -> 2 // 1 + 01, 10 + 0
 * dp[4]: 1010,        1001,  1000 -> 3 // 101 + 0. 10 + 01, 100 + 0
 * dp[5]: 10101, 10100,10010, 10001, 10000 -> 5
 * dp[6]: 101010,101001,101000, 100101, 100100, 100010, 100001, 100000 -> 8
 * (when the previous string ends with 1, concatenating 0 is the only case
 * when the previous string ends with 0, concatenating 0 or 1 these two cases exist)
 *
 * if the n is odd, dp[n - 1]
 * if the n is even, ...
 *
 * // first approach
 * previous
 * ~1: + 1
 * ~0: + 1 / + 0
 *
 * // answer approach
 * cases of dp[n - 1] + 0
 * cases of dp[n - 2] + 01
 *
 * -> dp[n] = dp[n - 1] + dp[n - 2]
 */