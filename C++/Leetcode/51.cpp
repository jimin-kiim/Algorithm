//
// Created by 김지민 on 5/15/25.
//
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        int chess_board[n][n];
        for (int i = 0; i < n; i++) {
            chess_board[i].fill(0);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // is there no Q in same column (i is same and j is different.)
                for (int c = j - 1; j - 1 >= 0; j--) {
                    if (chess_board[i][c] == 'Q' ) break;
                }

                // is there no Q in the same diagonal line. ()
                for (int r = i - 1; r >= 0; r--) {
                    for (int c = j - 1; c>=0; c--) {
                        if (chess_board[r][c] == 'Q') break;
                    }
                }

                chess_board[i][j] = 'Q';
            }
        }
    }
};

/*
 * N-Queens Problem
 * -> BF
 * -> Backtracking (Promising function is clear.)
 *
 */