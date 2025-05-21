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
        int result;
        for (int i = 0; i < n; i++) {
            result += recurrence(chess_board, 0, n, 0);
        }

    }

private:
    bool isSafe(vector<vector<char> > &chess_board, int row, int col, int n) {
        for (int r = row; r >= 0; r--) {
            if (chess_board[r][col] == 'Q') return false;
        }

        for (int r = row, c = col; r >= 0, c >= 0; r--, c--) {
            if(chess_board[r][c] == 'Q') return false;
        }

        for (int r = row, c = col; r >= 0, c < n; r--, c++) {
            if(chess_board[r][c] == 'Q') return false;
        }

        return true;
    }

    int recurrence(vector<vector<char> > &chess_board, int row, int n, int result) {
        if (row >= n) {
            return result + 1;
        }
        for (int col = 0; col < n; col++) {
            if (isSafe(chess_board, row, col, n)) {
                chess_board[row][col] = 'Q';
                recurrence(chess_board, row + 1, n, result);
                chess_board[row][col] = '.';
            }
        }
    }
};