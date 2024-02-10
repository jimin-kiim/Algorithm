//
// Created by 김지민 on 2/8/24.
//
#include <bits/stdc++.h>
using namespace std;

int score[301];
int dp[301];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> score[i];
    
    dp[1] = score[1];
    dp[2] = score[2];
    if (n > 2) dp[3] = score[3] + max(dp[1], dp[2]);

    for (int i = 3; i <= n; i++)
        dp[i] = score[i] + max(score[i - 1] + dp[i - 3], dp[i - 2]);

    cout << dp[n]; // 마지막 계단에서의 누적 점수 값 출력
}

/*
 * 시작 계단은 미정
 *
 */