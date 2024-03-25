//
// Created by 김지민 on 3/16/24.
//
#include <bits/stdc++.h>
using namespace std;

int n;
int seq[1001];
int dp[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> seq[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (seq[j] < seq[i]) {
                dp[i] = seq[i] + dp[j];
                break;
            }
        }
    }
    cout << *max_element(dp, dp + n);
}

/*
 * - using B-tree? N <= 1000 -> (X)
 * - DP 2 dimensional? -> while drawing the table, resulted out that 1D is sufficient
 * - DP 1 dimensional
 *  - for 0..i , for j..0  if j < i dp[j] + seq[i]
 */
