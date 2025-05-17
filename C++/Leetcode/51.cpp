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

    void recurrence(vector<vector<char>> chess_board, int row, int n, vector<vector<string>> & result) {
        if (row >= n) {
            vector<string> a_solution;
//            for (int i = 0; i < n; i++) {
//                string row_as_a_string(chess_board[i].begin(), chess_board[i].end()));
//                a_solution.push_back(row_as_a_string);
//            }
            for (const auto& each_row: chess_board) {
                a_solution.push_back(string(each_row.begin(), each_row.end())); // each row: vector<char>. convert the value into a single stirng.
            }
            result.push_back(a_solution);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (is_valid(chess_board, row, col, n)) {
                chess_board[row][col] = 'Q';
               recurrence(chess_board, row + 1, n, result);
            }
            chess_board[row][col] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> chess_board(n, vector<char> (n, '.'));
        vector<vector<string>> result;
        recurrence(chess_board, 0, n, result);

        return result;
    }
};


/*
 * N-Queens Problem
 * -> BF
 * -> Backtracking (Promising function is clear.)
 *
 */