//
// Created by 김지민 on 2023/08/29.
//
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[101][101];
int vis[101][101];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int n, m;
int step;

void count_step();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        for (int j = 0; j < m; j++) {
            board[i][j] = input[j] - '0';
        }
    }

    count_step();
    cout << step;
}

void count_step() {
    queue<pair<int, int> > q;
    q.push({0, 0});
    vis[0][0] = 1;
    step = 1;

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (board[nx][ny] == 0 || vis[nx][ny] == 1) continue;

            vis[nx][ny] = 1;
            q.push({nx, ny});
            step++;
            if (nx == n - 1 && ny == m - 1) return;
            break;
        }
    }
}