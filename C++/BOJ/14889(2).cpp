//
// Created by 김지민 on 2023/09/04.
//
#include <bits/stdc++.h>
using namespace std;

int min_val = 150;
int n;
int team[21];
int arr[21][21];

void func(int cur, int start_size) {
    if (start_size == n / 2) {
        int dif = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) continue;
                if (team[i] == team[j] && team[i] == 1) {
                    dif += arr[i - 1][j - 1];
                } else if (team[i] == team[j] && team[i] == 0) {
                    dif -= arr[i - 1][j - 1];
                }
            }
        }
        min_val = min(min_val, abs(dif));
        return;
    }
    if (cur == n) return;
    for (int i = cur; i <= n; i++) {
        func(cur + 1,  start_size);
        team[i] = 1;
        func(cur + 1, start_size + 1);
        team[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    func(0, 0);
    cout << min_val;
}