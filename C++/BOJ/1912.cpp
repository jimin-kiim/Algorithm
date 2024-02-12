//
// Created by 김지민 on 2/12/24.
//
#include <bits/stdc++.h>
using namespace std;

int score[100001];
int dp[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> score[i];
    for (int i = 1; i <= n; i++) {
        dp[i] = max(dp[i - 1], 0) + score[i];
    }
    cout << *max_element(dp + 1, dp + n + 1);
}