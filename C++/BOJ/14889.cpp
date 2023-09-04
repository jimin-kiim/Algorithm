//
// Created by 김지민 on 2023/09/03.
//
#include <bits/stdc++.h>
using namespace std;

int min_val = 150;
int n;
int team[21];
int arr[21][21];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    fill(team + n / 2, team + n, 1);
    do {
        int dif = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (team[i] != team[j]) continue;
                if (team[i] == 1) {
                    dif += arr[i][j] + arr[j][i];
                } else {
                    dif -= arr[i][j] + arr[j][i];
                }
            }
        }
        min_val = min(min_val, abs(dif));
    } while (next_permutation(team, team + n));
    cout << min_val;
}