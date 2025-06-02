//
// Created by 김지민 on 6/1/25.
//
#include <bits/stdc++.h>
using namespace std;

void recurrence(char seats[5][5], int is_used[5][5], int& result_count, vector<pair<int, int> >  sequence, int& count_y) {
    // termination condition
    if (sequence.size() == 7 ) {
        //if (s_count >= 4)
            result_count++; // when the number of S is at least 4, among the 7 position values.
        return;
    }

    // variable to be used when verifying the next cells around the current position
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};

    // selecting new subsequent elements; among the connected ones.
    for (int dir = 0; dir < 4; dir++) {
        pair<int, int> cur = sequence.back();
        int nx = cur.first + dx[dir];
        int ny = cur.second + dy[dir];

        // promising function - checking if it's a valid position
        if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
        if (is_used[nx][ny]) continue;
        if (seats[nx][ny] == 'Y') count_y++;
        if (count_y >= 4) {
            count_y--;
            continue;
        }

        // building a sequence
        is_used[nx][ny] = 1;
        sequence.push_back({nx, ny});

        // recurrence
        recurrence(seats, is_used, result_count, sequence, count_y);

        // backtracking
        is_used[nx][ny] = 0;
        if (seats[nx][ny] == 'Y') count_y--;
        sequence.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    char seats[5][5];
    int is_used[5][5];
    int result_count = 0;

    // getting input
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            char input;
            cin >> input;
            seats[i][j] = input;
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            vector<pair<int, int> > sequence;
            is_used[i][j] = 1;
            sequence.push_back({i, j});
            int count_y = seats[i][j] == 'Y' ? 1 : 0 ;
            recurrence(seats, is_used, result_count, sequence, count_y);
            sequence.pop_back();
        }
    }

    cout << result_count;
}