//
// Created by 김지민 on 3/12/24.
//
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1001];
int vis[1001];
int tot_count;

void bfs(int start);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // even a connected path ends, to find another one
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        bfs(i);
        tot_count++; // counting the number of connected paths
    }
    cout << tot_count;
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    vis[start] = 1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int closest: adj[cur]) {
            if (vis[closest]) continue;
            vis[closest] = 1;
            q.push(closest);
        }
    }
}