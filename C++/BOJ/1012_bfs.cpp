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

    // the number of test cases.
    int t;
    cin >> t;

    // resolve the problem; t times.
    for (int i = 0; i < t; i++) {
        initialize_boards();
        count_worm = 0;

        int k;
        // get the width and height of the field (board) & the number of the cabbages.
        cin >> n >> m >> k;

        // get the coordination values of the positions of the k cabbages.
        int x, y;
        for (int j = 0; j < k; j++) {
            cin >> x >> y;
            board[x][y] = 1;
        }

        // count how many worms are needed to keep the cabbage field healthy.
        count_worms();

        // print out the number of worms needed to keep the field healthy.
        cout << count_worm;

        // if it's not the last test case, print out a line break
        if (i != t - 1) cout << "\n";
    }
}

void count_worms() {
    queue<pair<int, int> > q; // BFS

    // 배추 영역 시작점 찾기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // if it's not a position where the cabbage is placed or already visited, pass and keep going finding out the cabbage.
            if (board[i][j] == 0 || vis[i][j]) continue;

            // 처음 도착한 배추 영역
            // when a cabbage is found, update the number of worm needed and mark the position visited.
            count_worm++;
            vis[i][j] = 1;
            q.push({i, j}); // store the current position in the queue

            // 한 마리의 배추 지렁이가 보호할 영역 돌기. 방문한 영역 표시
            // to mark the area verified as a range of a visited cabbage group.
            while (!q.empty()) {
                pair<int, int> cur = q.front();
                q.pop();

                // verifying how wide the cabbage field is and visit as a verified one.
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    // check if it's outside the field or already visited or not a cabbage.
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (vis[nx][ny] || board[nx][ny] == 0) continue;

                    // mark that it's visited
                    vis[nx][ny] = 1;
                    // update the latest position visited.
                    q.push({nx, ny});


                }
            }
        }
    }
}