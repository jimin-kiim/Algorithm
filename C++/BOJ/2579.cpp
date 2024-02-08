//
// Created by 김지민 on 2/8/24.
//
#include <bits/stdc++.h>
using namespace std;

int score[3001];
int res[301];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> score[i];

    res[0] = score[0];
    res[1] = score[1];

    int consecutive_count = 0;
    for (int i = 2; i <= n; i++) {
        if (consecutive_count == 1) {
            res[i] = res[i - 2] + score[i];
            consecutive_count = 0;
        } else {
            res[i] = max(res[i - 1], res[i - 2]) + score[i];
        }
        if (res[i] == res[i - 1] + score[i]) consecutive_count++;
    }
    cout << res[n];
}

/*
 * 시작 계단은 미정
 *
 */