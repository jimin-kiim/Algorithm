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

vector<vector<int> > solveNQueens(int n) {
    vector<vector<int> > solutions;
    queue<State> states;

    State initial_state;
    initial_state.row = 0;
    states.push(initial_state);

    while (!states.empty()) {
        State current_state = states.front();
        states.pop();

        int current_row = current_state.row;
        if (current_row == n) {
            solutions.push_back(current_state.queens);
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

    return solutions;
}

void printSolutions(const vector<vector<int> >& solutions) {
    int num_solutions = solutions.size();
    if (num_solutions == 0) {
        cout << "No solutions found.";
    } else {
        cout << "Found " << num_solutions << " solution(s):\n";
        for (const auto& solution : solutions) {
            for (int row = 0; row < solution.size(); row++) {
                for (int col = 0; col < solution.size(); col++) {
                    cout << (solution[row] == col ? "Q " : ". ");
                }
                cout << "\n";
            }
            cout << "\n";
        }
    }
}

int main() {
    int n = 4; // Board size

    vector<vector<int> > solutions = solveNQueens(n);
    printSolutions(solutions);

    return 0;
}
