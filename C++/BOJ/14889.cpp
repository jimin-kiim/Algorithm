//
// Created by 김지민 on 2023/09/03.
//
#include <bits/stdc++.h>
using namespace std;

int min_val = 150;
int n;
int team[21];
int arr[21][21];

void func(int cur, int start_size) {
    int start = 0;
    int link = 0;
    if (start_size == n / 2) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) continue;
                if (team[i] == team[j] && team[i] == 1) {
                    start += arr[i - 1][j - 1];
                } else if (team[i] == team[j] && team[i] == 0) {
                    link += arr[i - 1][j - 1];
                }
            }
        }
        int dif = start - link;
        if (dif < 0 ) {
            if (-dif < min_val) min_val = -dif;
        } else {
            if (dif < min_val) min_val = dif;
        }
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