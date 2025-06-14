//
// Created by 김지민 on 6/13/25.
//
#include<vector>
#include <bits/stdc++.h>
using namespace std;
#include<vector>
#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0;

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    int maps_height = maps.size();
    int maps_width = maps[0].size();

    int is_visited[101][101];
    int distance[101][101];

    queue<pair<int, int>> q;
    q.push({0,0});
    is_visited[0][0] = 1;
    distance[0][0] = 1;

    // int path_length = 0;

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];


            if (nx < 0 || nx >= maps_height || ny < 0 || ny >= maps_width) continue;
            if (maps[nx][ny] == 0) continue;
            if (is_visited[nx][ny]) continue;
            is_visited[nx][ny] = 1;
            q.push({nx, ny});
            // path_length++; -> 가장 짧은 길의 길이를 구하는 게 아니라 너비를 구한다.
            distance[nx][ny] = distance[cur.first][cur.second] + 1;
        }

    }
    if (distance[maps_height - 1][maps_width - 1] == 0 ) answer = -1;
    else answer = distance[maps_height - 1][maps_width - 1];
    // answer = path_length;
    return answer;
}

int main() {
    int answer = solution({{1,0,1,1,1},
              {1,0,1,0,1},
              {1,0,1,1,1},
              {1,1,1,0,1},
              {0,0,0,0,1}});

    cout << answer;

}