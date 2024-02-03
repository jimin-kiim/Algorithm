//
// Created by 김지민 on 2/3/24.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    vector<int> arr[101];
    int vis[101];
    int num;

    cin >> n >> num;
    for (int i = 0; i < num; i++) {
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    queue<int> q;
    q.push(1);
    vis[1] = 1;

    int count = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next: arr[cur]) {
            if (vis[next] == 1) continue;
            count++;
            vis[next] = 1;
            q.push(next);
        }
    }

    cout << count;
}