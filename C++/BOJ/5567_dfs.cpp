//
// Created by 김지민 on 3/11/24.
//
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> friends[501];
int vis[501];
int tot_count;

void dfs();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int f1, f2;
        cin >> f1 >> f2;
        friends[f1].push_back(f2);
        friends[f2].push_back(f1);
    }

    dfs();
    cout << tot_count;
}

void dfs() {
    stack<int> s;
    s.push(1);
    vis[1] = 1;

    while (!s.empty()) {
        int cur = s.top();
        s.pop();

        for (int f: friends[cur]) {
            if (vis[f] == 1) continue;
            tot_count++;
            vis[f] = 1;
            if (cur == 1) s.push(f);
        }
    }
}