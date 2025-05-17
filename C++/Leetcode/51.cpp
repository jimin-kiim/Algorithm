//
// Created by 김지민 on 5/15/25.
//
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> chess_board(n, vector<char> (n, '.'));
        vector<vector<string>> result;

        for (int i = 0; i < n; i++) {
            string row;
            for (int j = 0; j < n; j++) {
                // is there no Q in same column (i is same and j is different.)
                for (int c = j - 1; c >= 0; c--) {
                    if (chess_board[i][c] == 'Q' ) {
                        chess_board[i][j] = '.';
                        row += '.';
                        break;
                    }
                }

                // is there no Q in the same diagonal line. (left)
                for (int r = i - 1, c = j - 1; r >= 0 && c >= 0; c--, r--) {
                    if (chess_board[r][c] == 'Q') {
                        chess_board[i][j] = '.';
                        row += '.';
                        break;
                    }
                }

                // is there no Q in the same diagonal line. (right)
                for (int r = i - 1, c = j + 1; r >= 0 && c < n; r--, c++) {
                    if (chess_board[r][c] == 'Q') {
                        chess_board[i][j] = '.';
                        row += '.';
                        break;
                    }
                }
                chess_board[i][j] = 'Q';
                row += 'Q';
            }
            for (int j = 0; j < n; j++) {
                result[i].push_back(row);
            }
        }
        return result;
    }
};


/*
 * N-Queens Problem
 * -> BF
 * -> Backtracking (Promising function is clear.)
 *
 */