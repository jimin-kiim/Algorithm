//
// Created by 김지민 on 3/15/24.
//
#include <bits/stdc++.h>
using namespace std;

int board[9][9];
int vis[10];
vector<pair<int, int> > v;
int n;

#define X first
#define Y second

bool check_is_valid(int x, int y, int value) {
    for (int i = 0; i < 9; i++) {
        if (board[x][i] == value) return false;
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
        int flag = 0;
        if (vis[i] || !check_is_valid(x, y, i)) continue;
        board[x][y] = i;
        func(k + 1);

        if (!check_is_valid(x, y, i)) flag = 1;
        if (flag) {
            vis[i] = 1;
            func(k);
            vis[i] = 0;
        }
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