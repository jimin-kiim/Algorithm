//
// Created by 김지민 on 2023/05/15.
//

/*
 * M - coloring problem
 * determining if the graph can be colored with at most m colors
 * such that no two adjacent vertices of the graph are colored with the same color
 *
 * 1. Design:
 *      Design Approach: Backtracking(DFS)
 *      Step 1. designing promising function
 *              1) check adj nodes for the same color
 *      Step 2. DFS traverse, visit
 */

/*
 * 2. Implementation
 */

#include <iostream>
using namespace std;
#define V 4

void printSolution(int color[]);

// utility function
bool isSafe(bool graph[V][V], int color[]) {
    for (int i = 0; i < V; i++) { // row
        for (int j = i + 1; j < V; j++) { // column in the right side of the diagonal
            if (graph[i][j] && color[j] == color[i]) // color of adj vertices is the same
                return false;
        }
    }
    return true;
}

// main recursive function - backtracking
/*
 * m: # of colors
 * i: current vertex index
 */
bool graphColoring(bool graph[V][V], int m, int i, int color[V]) {
    if (i == V) { // all vertices are assigned colors
        if (isSafe(graph, color)) {
            printSolution(color);
            return true; // indicating valid solution
        }
        return false;
    }

    for (int j = 1; j <= m; j++) { // trying each color for the current vertex
        color[i] = j;

        if (graphColoring(graph, m, i + 1, color)) // a valid coloring has been found
            return true;

        color[i] = 0; // an invalid coloring has been found so withdrawing(backtracking)
    }

    return false;
}

void printSolution(int color[]) {
    cout << "Solution Exists:"
            " Following are the assigned colors \n";
    for (int i = 0; i < V; i++) {
        cout << " " << color[i];
    }
    cout << "\n";
}

int main() {
    bool graph[V][V] = {
            {0, 1, 1, 1},
            {1, 0, 1, 0},
            {1, 1, 0, 1},
            {1, 0, 1, 0},
    };

    int m = 3;
    int color[V];
    for (int i = 0; i < V; i++) {
        color[i] = 0;
    }

    if (!graphColoring(graph, m, 0, color)) // no valid coloring exists
        cout << "Solution does not exist";

    return 0;
}