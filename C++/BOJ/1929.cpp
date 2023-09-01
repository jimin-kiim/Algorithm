//
// Created by 김지민 on 2023/09/01.
//
#include <bits/stdc++.h>
using namespace std;

int arr[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    cin >> m >> n;
    for (int i = 2; i <= n; i++) {
        arr[i] = i;
    }

    for (int i = 2; i <= n; i++) {
        if (arr[i] == 0) continue;
        for (int j = 2*i; j <= n; j += i) {
            arr[j] = 0;
        }
    }
    for (int i = m; i <= n; i++) {
        if (arr[i] != 0) cout << i << "\n";
    }
}