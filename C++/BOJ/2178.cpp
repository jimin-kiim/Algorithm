//
// Created by 김지민 on 2023/08/29.
//
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[101][101];
int dist[101][101];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n, m;

void count_step();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    // n rows
    for (int i = 0; i < n; i++) {
        string input;
        // getting a row as a string.
        cin >> input;
        // storing the input in a board as a character as a unit.
        for (int j = 0; j < m; j++) {
            board[i][j] = input[j] - '0';
        }
    }

    // initializing all the values in the board for storing the steps taken to get to each cell as -1.
    for (int i = 0; i < n; i++) fill(dist[i], dist[i] + m, -1);

    count_step();
    // print out how many steps take to get to the position (N, M)
    cout << dist[n - 1][m - 1] + 1; // the number of cell which has been passed. = steps taken to get to the position
    cout << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << dist[i][j] << "  ";
        }
        cout << "\n";
    }
}

void count_step() {
    queue<pair<int, int> > q; // BFS.
    // storing the starting position in a queue.
    q.push({0, 0});
    // mark as visited.
    dist[0][0] = 0;

    while (!q.empty()) {
        pair<int, int> cur = q.front(); // when the first round, the starting position is stored in a queue and it's popped out.
        q.pop();

        // checking four directions around the current position to find out the next path.
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir]; // next x value.
            int ny = cur.Y + dy[dir]; // next y value.

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // verify if it's inside the board boundary.
            if (board[nx][ny] == 0 || dist[nx][ny] >= 0 ) continue; // verify if it's a dead end or already visited.
            
            q.push({nx, ny}); // if it's inside the board boundary and not a visited path, store it in a queue.
            dist[nx][ny] = dist[cur.X][cur.Y] + 1; // update the cumulative step value of the current position, increasing 1.
        }
    }
}

/*
 * if (board[nx][ny] == 0 || vis[nx][ny] == 1) continue;
 * vis[nx][ny] = 1;
 * step++;
 *
 * 로 할 경우 step++을 하는 데 있어 이미 다녀갔던 지점이나 막힌 길만 판단에서 제외시키는 것인데
 * 이미 다녀가지 않은 길이지만 더 가면 최소 거리 측정에 방해가 되는 길 역시 지나간 뒤 step을 증가시키는 게 되어
 * 문제가 발생한다.
 *
 * 그래서 이미 다녀가지 않은 길도 지나가며 표식을 하되 무조건 step을 1 증가시키는 게 아니라
 * 실질적인 최소 거리 측정 이동 방식으로 해당 지점에 오는 데 걸리는 step을 저장해 표시를 해야 한다.
 */