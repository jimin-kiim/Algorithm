//
// Created by 김지민 on 2/10/24.
//
#include <bits/stdc++.h>
using namespace std;

int dp[1001];
int mod = 10007;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    dp[1] = 1;
    dp[2] = 2; // ||, =
    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
    }
    cout << dp[n];
}

/*
 * 1 : 1
 * 2 : 2
 * 3 : 1 & 2, 2 & 1 (|= , =|, |||)
 * 4 : 1 & 3 , 3 & 1 (|3's, 3's|)
 * (2 & 2 넣게 되면 중복 경우 있을 것 같다)
 */

/*
 * 1, 2, 3, 5, 8 ..
 */

/*
 * ~ | : f(n - 1)
 * ~ = : f(n - 2)
 * => f(n - 1) + f(n - 2)
 * => fibonacci
 */