//
// Created by 김지민 on 2023/05/22.
//

/*
 * N-Queens Problem
 * the problem of placing N chess queens of an NxN chessboard so that no two queens attack each other.
 *
 * 1. Design:
 *      Design Approach: Backtracking(DFS)
 *      Step 1. designing promising function
 *      Step 2. DFS traverse, visit
 */

/*
 * 2. Implementation
 */
#include <iostream>
#include <vector>
using namespace std;
int N;

// printing the solution
void printSol(vector<vector<int> >board) {
    for (int i  = 0; i<N; i++) {
        for (int j = 0; j<N; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

// checking if current row, left diagonal, right diagonal contain any queen
bool isSafe(int row, int col, vector<bool> rows, vector<bool> left_diagonals, vector<bool> right_diagonals) {
    if (rows[row] || left_diagonals[row + col] || right_diagonals[col - row + N - 1]) {
        return false;
    }
    return true;
}

// recursive function for N-queens problem
bool solve(vector<vector<int> >& board, int col, vector<bool> rows, vector<bool> left_diagonals, vector<bool> right_diagonals) {

    // all queens are placed
    if (col >= N) {
        return true;
    }

    // move in all rows one by one
    for (int i = 0; i < N; i++) {
        if (isSafe(i, col, rows, left_diagonals, right_diagonals)) { // placing a queen
            rows[i] = true;
            left_diagonals[i + col] = true;
            right_diagonals[col - i + N - 1] = true;
            board[i][col] = 1;

            // recurrence
            if (solve(board, col + 1, rows, left_diagonals, right_diagonals)) {
                return true;
            }

            // backtracking
            rows[i] = false;
            left_diagonals[i + col] = false;
            right_diagonals[col - i + N - 1] = false;
            board[i][col] = 0;
        }
    }
    return false;
}

int main() {
    cout << "Enter the no of rows for the square Board : ";
    cin >> N;

    vector<vector<int> > board(N,vector<int>(N,0));

    vector<bool> rows(N,false);

    vector<bool> left_diagonals(2*N-1,false);
    vector<bool> right_diagonals(2*N-1,false);

    bool ans =  solve(board, 0, rows, left_diagonals, right_diagonals);

    if (ans) {
        printSol(board);
    } else {
        cout<<"Solution Does not Exist\n";
    }
}