//
// Created by 김지민 on 2/2/24.
//
#include <bits/stdc++.h>
using namespace std;

// 정점 개수: n, 간선 개수: m, 시작 정점: start
int n, m, start;

// 인덱스: 정점 넘버, 데이터: 간선으로 연결된 정점 인덱스
vector<int> adj[1001];

// 인덱스: 정점 넘버, 데이터: 방문 여부
int vis[1001];

void dfs(); // 스택 이용
void bfs(); // 큐 이용

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

    // 정점 번호 작은 것부터 방문하는 조건 적용
    for(int i = 1; i <= n; i++)
        sort(adj[i].begin(), adj[i].end());

    dfs();
    cout << "\n";
    fill(vis + 1, vis + n + 1, 0); // bfs 하기 전 다시 초기화
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
            int next = adj[cur][adj[cur].size() - 1 - i]; // 스택이라서 역순
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

        for (int next : adj[cur]) { // 큐니까 순차적으로
            if (vis[next] == 1) continue;
            q.push(next);
            vis[next] = 1;
        }
    }
}