//
// Created by 김지민 on 3/15/24.
//
#include <bits/stdc++.h>
using namespace std;

int board[9][9];
vector<pair<int, int> > v;
#define X first
#define Y second
int n;

bool check_is_valid(int x, int y, int value) {
    for (int i = 0; i < 9; i++) {
        if (board[x][i] == value) return false;
    }

    for (int i = 0; i < 9; i++) {
        if (board[i][y] == value) return false;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + 3 * (x / 3)][j + 3 * (y / 3)] == value) return false;
        }
    }
    return true;
}

void func(int k) {
    if (k == n) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
        return;
    }

    for (int i = 1; i <= 9; i++) {
        int x, y;
        x = v[k].X;
        y = v[k].Y;
        if (!check_is_valid(x, y, i)) continue;
        board[x][y] = i;
        func(k + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int input;
            cin >> input;
            board[i][j] = input;
            if (!input) v.push_back({i, j});
        }
    }
    n = v.size();
    func(0);
}