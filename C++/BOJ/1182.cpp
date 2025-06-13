//
// Created by 김지민 on 2023/08/31.
//
#include <bits/stdc++.h>
using namespace std;

int n, s;
int palette[21];
int cnt = 0;

void func(int cur, int sum) {
    // termination condition
    if (cur == n) { // when reached the leaf node.
        if (sum == s) cnt++;
        return;
    }

    func(cur + 1, sum); // excluding current number
    func(cur + 1, sum + palette[cur]); // including current number
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    for (int i = 0; i < n; i++) cin >> palette[i];
    func(0, 0);

    if (s == 0) cnt--; // the size of a subset should be at least 1
    cout << cnt;
}