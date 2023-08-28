//
// Created by 김지민 on 2023/08/28.
//
#include <bits/stdc++.h>
using namespace std;

int mat[501][501];
bool vis[501][501];
int row, col;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> row >> col;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> mat[i][j];
        }
    }

    int count = 0;
    int max_area = 0;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (vis[i][j] || mat[i][j] != 1) continue;

            count++;
            queue<pair<int, int> > q;
            vis[i][j] = 1;
            q.push({i, j});

            int area = 0;
            while(!q.empty()) {
                pair<int, int> cur = q.front();
                q.pop();
                area++;

                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];

                    if (nx < 0 || ny < 0 || nx >=  row || ny >= col) continue;
                    if (vis[nx][ny] || mat[nx][ny] != 1) {
                        vis[nx][ny] = 1;
                        continue;
                    }

                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
            if (area > max_area) max_area = area;
        }
    }
    cout << count << "\n" << max_area;
}