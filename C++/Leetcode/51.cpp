//
// Created by 김지민 on 5/15/25.
//
class Solution {
public:
    bool solveNQUtil(int board[N][N], int col) {

        // terminating the recurrence
        if (col >= N)
            return true;

        for (int i = 0; i < N; i++) {

            // checking if the queen can be placed on board[i][col]
            if (isSafe(board, i, col)) {

                // placing the queen
                board[i][col] = 1;

                printSolution(board);
                cout << endl;

                // recur to place rest of the queens
                if (solveNQUtil(board, col + 1))
                    return true;

                // if placing the queen doesn't lead to a solution, remove queen
                // BACKTRACKING
                board[i][col] = 0;
            }
        }

        return false;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> chess_board(n, vector<char> (n, '.'));
        vector<vector<string>> result;

        for (int i = 0; i < n; i++) {
            string row;
            for (int j = 0; j < n; j++) {
                // is there no Q in same column (i is same and j is different.)
                for (int c = j - 1; c >= 0; c--) {
                    if (chess_board[i][c] == 'Q' ) {
                        row += '.';
                        break;
                    }
                }

                // is there no Q in the same diagonal line. ()
                for (int r = i - 1, c = j - 1; r >= 0 && c >=0; c--, r--) {
                    if (chess_board[r][c] == 'Q') {
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