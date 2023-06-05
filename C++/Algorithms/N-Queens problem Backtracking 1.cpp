//
// Created by 김지민 on 2023/05/15.
//
/*
 * N-Queens Problem
 * the problem of placing N chess queens of an NxN chessboard so that no two queens attack each other.
 *
 * 1. Design:
 *      Design Approach: Backtracking(DFS)
 *      Step 1. designing promising function
 *              no two queens attack each other
 *      Step 2. DFS traverse, visit
 *
 */

/*
 * 2. Implementation
 */

#include <iostream>
#define N 4
using namespace std;

void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j]) {
                cout << "Q ";
            } else {
                cout << ". ";
            }
        }
        printf("\n");
    }
}

// checking if a queen can be placed on board[row][col]
// this function is called when "col" queens are already placed in columns from 0 to col - 1
// so we need to check only left side for attacking queens
bool isSafe(int board[N][N], int row, int col) {
    int i, j;

    // checking the row on the left side
    for (i = 0; i < col; i++){
        if (board[row][i])
            return false;
    }

    // checking the upper diagonal on the left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])
            return false;
    }

    // checking the lower diagonal on the left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--) {
        if (board[i][j])
            return false;
    }

    return true;
}

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

bool solveNQ() {
    int board[N][N] = { {0, 0, 0, 0},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0}};

    if (solveNQUtil(board, 0) == false) {
        cout << "Solution does not exist";
        return false;
    }

    printSolution(board);
    return true;
}

int main() {
    solveNQ();
    return 0;
}