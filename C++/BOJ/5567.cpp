//
// Created by 김지민 on 3/10/24.
//
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> friends[501];
int vis[501];
int tot_count;

void bfs();

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int f1, f2;
        cin >> f1 >> f2;
        friends[f1].push_back(f2);
        friends[f2].push_back(f1);
    }

    bfs();
    cout << tot_count;
}

void bfs() {
    queue<int> q;
    q.push(1);
    vis[1] = 1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int f: friends[cur]) {
            if (vis[f] == 1) continue;

            tot_count++;
            vis[f] = 1;

            if (cur == 1) q.push(f);
        }
    }
}

/*
 * traversing graph
 * but if the distance is more than 2, it doesn't increase the count
 * traversing bfs only in two depth
 */