//
// Created by 김지민 on 5/21/25.
//
#include <bits/stdc++.h>
using namespace std;

// N Queens problem 1. BF - too many possible cases
//                  => 2. Backtracking(pruning with promising function)
//                  => recurrence
//                      => termination condition + visiting node + promising function + recurrence + backtracking
// promising function:
//              - two queens cannot be placed in a same row/column and diagonal line

class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<char> > chess_board(n, vector<char>(n, '.'));
        int result = 0;
        recurrence(chess_board, 0, n, result);
        return result;
    }

private:
    bool isValid(vector<vector<char> > &chess_board, int row, int col, int n) {
        // verify same column
        for (int r = row - 1; r >= 0; r--) {
            if (chess_board[r][col] == 'Q') return false;
        }

        // verify same diagonal(left)
        for (int r = row - 1, c = col - 1; r >=0 && c >= 0; r--, c--) {
            if(chess_board[r][c] == 'Q') return false;
        }

        // verify same diagonal(right)
        for (int r = row - 1, c = col + 1; r >= 0 && c < n; r--, c++) {
            if(chess_board[r][c] == 'Q') return false;
        }
        return true;
    }

    void recurrence(vector<vector<char> > &chess_board, int row, int n, int& result) {
        // termination
        if (row >= n) {
            result += 1;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << chess_board[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
            return;
        }

        for (int col = 0; col < n; col++) {
            // promising function
            if (isValid(chess_board, row, col, n)) {
                // visiting node and building the solution
                chess_board[row][col] = 'Q';
                // DFS
                recurrence(chess_board, row + 1, n, result);
            }
            // backtracking
            chess_board[row][col] = '.';
        }
    }
};

int main() {
    Solution solution;
    solution.totalNQueens(4);
}