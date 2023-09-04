//
// Created by 김지민 on 2023/09/03.
//
#include <bits/stdc++.h>
using namespace std;

int min_val = 150;
int n;
//vector<int> start;
int palette[21];
int arr[21][21];

void func(int cur, int size) {
    int start = 0;
    int link = 0;
    if (size == n / 2) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && palette[i] == 1 && palette[i] == palette[j]) {
                    start += arr[i][j];
                } else if (i != j && palette[i] == 0 && palette[i] == palette[j]) {
                    link += arr[i][j];
                }
            }
        }
        int dif = start - link;
        if (dif < 0 ) {
            if (-dif < min_val) min_val = -dif;
        } else {
            if (dif < min_val) min_val = dif;
        }
    }
//    else if (cur == n) {
//        start.erase(start.begin(), start.end());
//        return;
//    }
    for (int i = cur; i <= n; i++) {
        func(cur + 1, size);
//        s.push_back(cur)
        palette[cur] = 1;
        func(cur + 1, size + 1);
        palette[cur] = 0;
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

// 4C2 조합 -> dfs