//
// Created by 김지민 on 6/1/25.
//
#include <bits/stdc++.h>
using namespace std;

void recurrence(char seats[5][5], int is_visited[5][5], int x, int y, int& result_count, string sequence, int& count_y) {
    // termination condition
    if (sequence.size() == 7) {
        if (count_y <= 3) result_count++; // when the number of S is at least 4, among the 7 position values.
        return;
    }

    // variable to be used when verifying the next cells around the current position
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};

    // starting a new sequence; selecting starting point for the new sequence
    for (int i = x; i < 5; i++) {
        for (int j = y; j < 5; j++) {
            // promising function - minimum condition not to proceed building current sequence;
            if (!is_visited[x][y] && count_y <= 3) {
                // building a sequence; storing as the element for the sequence and marking as visited.
                is_visited[x][y] = 1;
                sequence.push_back(seats[x][y]);
                if (seats[x][y] == 'Y') count_y++;

                // before calling the recurrence function, determining the parameter value.
                for (int dir = 0; dir < 4; dir++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];

                    // before calling the recurrence function, verify if the parameters are valid as a position coordinates.
                    if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
                    if (is_visited[nx][ny]) continue;
                    recurrence(seats, is_visited, nx, ny, result_count, sequence, count_y);
                }

                // backtracking
                is_visited[x][y] = 0;
                if (seats[x][y] == 'Y') count_y--;
                sequence.pop_back();
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    char seats[5][5];
    int is_visited[5][5];
    int result_count = 0;
    string sequence = "";

    // getting input
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            char input;
            cin >> input;
            seats[i][j] = input;
        }
    }

    recurrence(seats, is_visited, 0, 0, result_count, sequence, result_count );
    cout << result_count;
}