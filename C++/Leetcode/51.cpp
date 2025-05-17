//
// Created by 김지민 on 5/15/25.
//

/*
 * placing queens ~= building n permutations, each has three '.' and one 'Q'.
 * permutation => backtracking
 * clear promising function => backtracking
 *
 * backtracking => recurrence function.
 * recurrence function => termination condition +  promising function + building the solution + recurrence + backtracking)
 */
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
            // termination condition
        if (row >= n) {
            vector<string> a_solution;

            for (const auto& each_row: chess_board) {
                a_solution.push_back(string(each_row.begin(), each_row.end())); // each row: vector<char>. convert the value into a single stirng.
            }
            result.push_back(a_solution);
            return;
        }

        for (int col = 0; col < n; col++) {
            // promising function
            if (is_valid(chess_board, row, col, n)) { // too long so extracted as a separated function
                // building a solution
                chess_board[row][col] = 'Q';
                // recurrence
               recurrence(chess_board, row + 1, n, result);
            }
            // backtracking
            chess_board[row][col] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
            // initializing
        vector<vector<char>> chess_board(n, vector<char> (n, '.'));
        vector<vector<string>> result;

        // start solving the problem
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