//
// Created by 김지민 on 2023/04/28.
//

/*
 * Prim's Algorithm - node based
 * for MST(Minimum Spanning Tree)
 *
 * 1. Design:
 *      Design Approach: Greedy Algorithm
 *      Step 1. selection(local optimal choice, ranking)
 *      ( Step 2. feasibility(constraint) ) - X. no cycle would be created
 *      Step 3. solution check(termination)
 *
 */

/*
 * 2. Implementation
 */
#include <iostream>
using namespace std;

#define V 5

int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (mstSet[v] == false && key[v] < min) { // not yet included in MST T. pick minimum weight edge
            min = key[v], min_index = v;
        }
    }
    return min_index;
}

void printMST(int parent[], int graph[V][V]) {
    cout << "Edge \tWeight \n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " \t  " << graph[i][parent[i]] << " \n";
    }
}

void primMST(int graph[V][V]) {
    int parent[V]; // Array to store constructed MST. T = (V, F)
    int key[V];
    bool mstSet[V]; // Y

    // initialization
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX, mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet); // pick a vertex u that is not in mstSet and has a minimum key value.
        mstSet[u] = true; // include u in the mstSet

        for (int v = 0; v < V; v++) {
            if (graph[u][v] // there exists edge. iterating only adjacent vertices
            && mstSet[v] == false // not in the mstSet yet
            && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v]; // update the key value of all adjacent vertices of u.
        }
    }
    printMST(parent, graph);
}

int main() {
    int graph[V][V] = { {0, 2, 0, 6, 0},
                        {2, 0, 3, 8, 5},
                        {0, 3, 0, 0, 7},
                        {6, 8, 0, 0, 9},
                        {0, 5, 7, 9, 0}
    };
    primMST(graph);

    return 0;
}
/*
 * 3. Analysis
 *
 * T(n) = T(|V|)
 *      = (n - 1)(n - 2)
 *      ~= O(n^2)
 */