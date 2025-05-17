//
// Created by 김지민 on 5/15/25.
//
class Solution {
public:
        bool is_valid(vector<vector<char>> chess_board, int row, int col, int n) {
            // is there no Q in same column (i is same and j is different.)
            for (int r = row - 1; r >= 0; r--) {
                if (chess_board[r][col] == 'Q' ) return false;
            }

            // is there no Q in the same diagonal line. (left)
            for (int r = row - 1, c = col - 1; r >= 0 && c >= 0; c--, r--) {
                if (chess_board[r][c] == 'Q') return false;
            }

            // is there no Q in the same diagonal line. (right)
            for (int r = row - 1, c = col + 1; r >= 0 && c < n; r--, c++) {
                if (chess_board[r][c] == 'Q') return false;
            }

            return true;
    }

    void recurrence(vector<vector<char>> chess_board, int row, int n, vector<vector<char>> & result) {
        string result_row;
        for (int col = 0; col < n; col++) {
            if (is_valid(chess_board, row, col, n)) {
                chess_board[row][col] = 'Q';
                result_row += 'Q';
               recurrence(chess_board, row + 1, n, result);
            }
            chess_board[row][col] = '.';
            result_row += '.';
        }
        result.push_back(result_row);
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> chess_board(n, vector<char> (n, '.'));
        vector<vector<string>> result;

        for (int row = 0; row < n; row++) {
            recurrence(chess_board, row, n, result);
        }
        result.push_back()
    }
};


/*
 * N-Queens Problem
 * -> BF
 * -> Backtracking (Promising function is clear.)
 *
 */