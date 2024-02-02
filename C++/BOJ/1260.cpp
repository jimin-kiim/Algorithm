//
// Created by 김지민 on 2/2/24.
//
#include <bits/stdc++.h>
using namespace std;

int n, m, start;
vector<int> adj[1001];
int vis[1001];

void dfs();
void bfs();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> start;

    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1; i <= n; i++)
        sort(adj[i].begin(), adj[i].end());

    dfs();
    cout << "\n";
    fill(vis + 1, vis + n + 1, 0);
    bfs();
}

void dfs() {
    stack<int> s;
    s.push(start);

    while (!s.empty()) {
        int cur = s.top();
        s.pop();
        if (vis[cur] == 1) continue;
        vis[cur] = 1;
        cout << cur << " ";

        for(int i = 0; i < adj[cur].size(); i++) {
            int next = adj[cur][adj[cur].size() - 1 - i];
            if (vis[next] == 1) continue;
            s.push(next);
        }
    }
}

void bfs() {
    queue<int> q;
    q.push(start);
    vis[start] = 1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << " ";

        for (int next : adj[cur]) {
            if (vis[next] == 1) continue;
            q.push(next);
            vis[next] = 1;
        }
    }
}