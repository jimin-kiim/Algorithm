//
// Created by 김지민 on 1/25/24.
//
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[100][100];
bool vis[100][100];

int n, m;
int num = 0;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

vector<int> areas;

void color_rectangle(int x1, int y1, int x2, int y2) {
    for (int i = x1; i < x2; i++) {
        for (int j = y1; j < y2; j++) {
            board[i][j] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

void count_space();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        color_rectangle(x1, y1, x2, y2);
    }
    count_space();
    sort(areas.begin(), areas.end());
    cout << num << "\n";
    for (int i = 0; i < areas.size(); i++) {
        cout << areas[i];
        if (i != areas.size() - 1) cout << " ";
    }
}

void count_space() {
    queue<pair<int, int> > q;

    // 새로운 영역 찾기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            // 이미 방문한 곳이거나 사각형 영역이면 패스
            if (board[i][j] == 1 || vis[i][j] == 1) continue;

            // 새로운 영역 찾기 성공
            vis[i][j] = 1;
            num++;
            q.push({i, j});
            int area = 1;

            while (!q.empty()) {
                pair<int, int> cur = q.front();
                q.pop();

                // 하나의 영역 돌면서 방문 체크 + 영역 넓이 구하기
                for (int dir = 0; dir < 4; dir++) {
                    int nx, ny;
                    nx = cur.X + dx[dir];
                    ny = cur.Y + dy[dir];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (board[nx][ny] == 1 || vis[nx][ny] == 1) continue;

                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
                area++;
            }
            areas.push_back(area);
        }
    }
}