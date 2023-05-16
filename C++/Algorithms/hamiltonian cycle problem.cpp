//
// Created by 김지민 on 2023/05/15.
//

/*
 * Hamiltonian Cycle
 * finding a path that visits each vertex of the graph exactly once.
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

#define V 5

void printSolution(int path[]);

// utility function
bool isSafe(int v, bool graph[V][V], int path[], int pos) {

    // is there an edge between the previously added vertex and the current vertex
    if (graph [path[pos - 1]][v] == 0)
        return false;

    // has the vertex already been included
    for (int i = 0; i < pos; i++) {
        if (path[i] == v)
            return false;
    }
    return true;
}

// main recursive function
bool hamCycleUtil(bool graph[V][V], int path[], int pos) {

    // all vertices are included in the cycle
    if (pos == V) {
        // is there an edge between the vertex lastly included and the first vertex
        if (graph[path[pos - 1]][path[0]] == 1) {
            return true; // a valid solution is found
        } else {
            return false;
        }
    }

    for (int v = 1; v < V; v++) { // as 0 is a starting point, can start from 1
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;
            if (hamCycleUtil(graph, path, pos + 1))
                return true; // indicating valid path

            path[pos] = -1; // path found as a invalid one. backtracking
        }
    }
    return false;
}

// there may be more than one solutions, this function prints one of the feasible sollutions.
bool hamCycle(bool graph[V][V]) {
    int *path = new int[V];
    for (int i = 0; i < V; i++)
        path[i] = -1;

    path[0] = 0; // putting vertex 0 as the first vertex in the path
    if (!hamCycleUtil(graph, path, 1)) { // no valid path has been found
        cout << "\nSolution does not exist";
        return false;
    }

    printSolution(path);
    return true;
}

void printSolution(int path[]) {
    cout << "Solution Exists: "
            " Following is one Hamilton Cycle \n";
    for (int i = 0; i < V; i++)
        cout << path[i] << " ";

    cout << path[0] << " ";
    cout << endl;
}

int main() {
    bool graph1[V][V] = {{0, 1, 0, 1, 0},
                        {1, 0, 1, 1, 1},
                        {0, 1, 0, 0, 1},
                        {1, 1, 0, 0, 1},
                        {0, 1, 1, 1, 0}};

    hamCycle(graph1);

    bool graph2[V][V] = {{0, 1, 0, 1, 0},
                         {1, 0, 1, 1, 1},
                         {0, 1, 0, 0, 1},
                         {1, 1, 0, 0, 0},
                         {0, 1, 1, 0, 0}
                         };
    hamCycle(graph2);

    return 0;
}