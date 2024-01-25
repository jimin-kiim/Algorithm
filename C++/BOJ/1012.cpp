//
// Created by 김지민 on 1/20/24.
//
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m;
int count_worm;

int board[50][50];
bool vis[50][50];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void initialize_boards() {
    for (int i = 0; i < 50; i++) {
        fill(board[i], board[i] + 50, 0);
        fill(vis[i], vis[i] + 50, 0);
    }
}

void count_worms();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        initialize_boards();
        count_worm = 0;

        int k;
        cin >> n >> m >> k;

        int x, y;
        for (int j = 0; j < k; j++) {
            cin >> x >> y;
            board[x][y] = 1;
        }

        count_worms();
        cout << count_worm;
        if (i != t - 1) cout << "\n";
    }
}

void count_worms() {
    queue<pair<int, int> > q;

    // 배추 영역 시작점 찾기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // 배추 없는 곳이나 이미 방문한 위치면 패스
            if (board[i][j] == 0 || vis[i][j]) continue;

            // 처음 도착한 배추 영역
            count_worm++;
            vis[i][j] = 1;
            q.push({i, j});

            // 한 마리의 배추 지렁이가 보호할 영역 돌기. 방문한 영역 표시
            while (!q.empty()) {
                pair<int, int> cur = q.front();
                q.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (vis[nx][ny] || board[nx][ny] == 0) continue;

                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }
}