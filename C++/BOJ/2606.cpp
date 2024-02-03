//
// Created by 김지민 on 2/3/24.
//
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr[101];
int vis[101];
int num;
int cnt;

void bfs();
void dfs();
void dfs2(int cur);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> num;
    for (int i = 0; i < num; i++) {
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

//    bfs();
//    dfs();
    dfs2(1);

    cout << cnt;
}

void bfs() {
    queue<int> q;
    q.push(1);
    vis[1] = 1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next: arr[cur]) {
            if (vis[next] == 1) continue;
            cnt++;
            vis[next] = 1;
            q.push(next);
        }
    }
}

void dfs() {
    stack<int> s;
    s.push(1);

    while (!s.empty()) {
        int cur = s.top();
        s.pop();
        if (vis[cur] == 1) continue;
        vis[cur] = 1;
        if (cur != 1) cnt++;

        for (int i = 0; i < arr[cur].size(); i++) {
            int next = arr[cur][arr[cur].size() - 1 - i];
            if (vis[next] == 1) continue;
            s.push(next);
        }
    }
}

void dfs2(int cur) {
    vis[cur] = 1;

    for (int next: arr[cur]) {
        if (vis[next] == 1) continue;
        cnt++;
        dfs2(next);
    }
}