//
// Created by 김지민 on 2023/09/03.
//
#include <bits/stdc++.h>
using namespace std;

int min_val = 150;
int n;
vector<int> s;
vector<int> l;
int arr[21][21];

void func(int cur, vector<int>& s, vector<int>& l) {
    int start = 0;
    int link = 0;
    if (s.size() == n / 2) {
        for (int e1: s) {
            for (int e2: s) {
                start += arr[e1][e2];
            }
        }
        for (int e1: l) {
            for (int e2: l) {
                link += arr[e1][e2];
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
    for (int i = cur; i <= n; i++) {
        l.push_back(cur);
        func(cur + 1,  s, l);
        l.pop_back();

        s.push_back(cur);
        func(cur + 1, s, l);
        s.pop_back();
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
    func(0, s, l);
    cout << min_val;
}