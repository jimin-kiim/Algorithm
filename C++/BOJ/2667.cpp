//
// Created by 김지민 on 1/31/24.
//
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[25][25];
int vis[25][25];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int n;
vector<int> nums;

void count_nums();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        for (int j = 0; j < n; j++) {
            board[i][j] = input[j] - '0';
        }
    }

    count_nums();
    sort(nums.begin(), nums.end());
    cout << nums.size() << "\n";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i != nums.size() - 1) cout << "\n";
    }
}

void count_nums() {
    queue<pair<int, int> > q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 0 || vis[i][j] == 1) continue;

            q.push({i, j});
            vis[i][j] = 1;
            int count = 1;

            while(!q.empty()) {
                pair<int, int> cur = q.front();
                q.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (board[nx][ny] == 0 || vis[nx][ny] == 1) continue;

                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                    count++;
                }
            }
            nums.push_back(count);
        }
    }
}