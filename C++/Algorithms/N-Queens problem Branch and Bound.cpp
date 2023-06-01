//
// Created by 김지민 on 2023/06/01.
//

/*
 * N-Queens Problem
 * the problem of placing N chess queens of an NxN chessboard so that no two queens attack each other.
 *
 * 1. Design:
 *      Design Approach: Branch and Bound(BFS)
 *      Step 1. designing promising function
 *      Step 2. BFS traverse, visit
 */

/*
 * 2. Implementation
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct State {
    vector<int> queens;
    int row;
};

bool isSafe(const vector<int>& queens, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (queens[i] == col || queens[i] - col == i - row || queens[i] - col == row - i) {
            return false;
        }
    }
    return true;
}

vector<int> solveNQueens(int n) {
    vector<int> queens(n, -1); // to store column positions of queens
    // queens[row] : the column position of the queen in the row-th row
    queue<State> states; // to store the states to be explored

    State initial_state;
    initial_state.row = 0;
    states.push(initial_state);

    while (!states.empty()) {
        State current_state = states.front();
        states.pop();

        int current_row = current_state.row;
        if (current_row == n) { // all queens have been placed
            queens = current_state.queens;
            break;
        } else {
            for (int col = 0; col < n; col++) {
                if (isSafe(current_state.queens, current_row, col)) {
                    State new_state = current_state;
                    new_state.queens.push_back(col);
                    new_state.row++;

                    states.push(new_state);
                }
            }
        }
    }

    return queens;
}

void printSolution(const vector<int>& queens) {
    int n = queens.size();
    if (queens.empty()) {
        cout << "No solution found.";
    } else {
        cout << "Found a solution:\n";
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                cout << (queens[row] == col ? "Q " : ". ");
            }
            cout << "\n";
        }
    }
}

int main() {
    int n = 4; // Board size

    vector<int> solution = solveNQueens(n);
    printSolution(solution);

    return 0;
}