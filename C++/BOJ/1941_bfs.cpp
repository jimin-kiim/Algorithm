//
// Created by 김지민 on 6/1/25.
//
#include <bits/stdc++.h>
using namespace std;

// find the first S and then go to the possible paths. if a path includes at least 4 S and its length us 7,
// update the number of the paths.

void count_possible_ways(int& count, char seats[5][5], int is_visited[5][5]) {
    queue<pair<int, int> > q;

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};

    string sequence;
    int count_y = 0;

    // finding the point that would be the starting point of the group
    for (int i = 0; i < 5; i++) { // once visited, the position value excluded in the finding space so it's not that consuming process.
        for (int j = 0; j < 5; j++) {
            if (is_visited[i][j]) continue;
            is_visited[i][j] = 1;
            q.push({i, j});

            // finding out the border of the group
            while (!q.empty()) {
                pair<int, int> cur = q.front();
                q.pop();


                if (count_y >= 4) continue;
                if (sequence.length() == 7) {
                    count++;
                    sequence.pop_back();
                    continue;
                }

                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];

                    if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 ) continue;
                    if (is_visited[nx][ny]) continue;
                    if (seats[nx][ny] == 'Y') count_y++;

                    // if the length is over than 7 => S 개수 확인 후 4개 이상이면 포함시킨다.

                    is_visited[nx][ny] = 1;
                    q.push({nx, ny});
                    sequence.push_back({seats[nx][ny]});
                }
            }

        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    char seats[5][5];
    int is_visited[5][5];

    int count = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            char input;
            cin >> input;
            seats[i][j] = input;
        }
    }

    count_possible_ways(count, seats, is_visited);
    cout << count;
}