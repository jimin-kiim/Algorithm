//
// Created by 김지민 on 2023/06/06.
//

/*
 * Traveling Salesman Problem(TSP)
 * finding the shortest possible tour that visits every city exactly once and returns to the starting point.
 *
 * BFS + Branch and Bound Technique
 *  1. Design:
 *      Design Approach: Branch and Bound(BFS)
 *      Step 1. designing bound function
 *      Step 2. BFS traverse, visit
 *
 */

/*
 * 2. Implementation
 */
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int N = 4;

struct Node {
    int curr_path[N + 1];
    bool visited[N];
    int curr_bound;
    int curr_weight;
    int level;
};

int final_path[N + 1]; // storing the final solution
int final_res = INT_MAX; // final minimum weight of the shortest tour.

void copyToFinal(const int curr_path[]) {
    for (int i = 0; i < N; i++) {
        final_path[i] = curr_path[i];
    }
    final_path[N] = curr_path[0];
}

int firstMin(int adj[N][N], int i) {
    int min = INT_MAX;
    for (int k = 0; k < N; k++) {
        if (adj[i][k] < min && i != k) {
            min = adj[i][k];
        }
    }
    return min;
}

int secondMin(int adj[N][N], int i) {
    int first = INT_MAX, second = INT_MAX;
    for (int j = 0; j < N; j++) {
        if (i == j) {
            continue;
        }
        if (adj[i][j] <= first) {
            second = first;
            first = adj[i][j];
        } else if (adj[i][j] <= second && adj[i][j] != first) {
            second = adj[i][j];
        }
    }
    return second;
}

void TSP(int adj[N][N]) {
    int curr_path[N + 1];
    bool visited[N];
    int curr_bound = 0;
    memset(curr_path, -1, sizeof(curr_path));
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < N; i++) {
        curr_bound += (firstMin(adj, i) + secondMin(adj, i));
    }
    curr_bound = (curr_bound & 1) ? curr_bound / 2 + 1 : curr_bound / 2;

    visited[0] = true;
    curr_path[0] = 0;

    queue<Node> q;
    Node start;
    start.level = 0;
    start.curr_weight = 0;
    start.curr_bound = curr_bound;
    memcpy(start.curr_path, curr_path, sizeof(curr_path));
    memcpy(start.visited, visited, sizeof(visited));
    q.push(start);

    while (!q.empty()) {
        Node curr_node = q.front();
        q.pop();

        int curr_level = curr_node.level;
        int curr_weight = curr_node.curr_weight;
        int curr_bound = curr_node.curr_bound;
        memcpy(curr_path, curr_node.curr_path, sizeof(curr_path));
        memcpy(visited, curr_node.visited, sizeof(visited));

        if (curr_level == N - 1) {
            if (adj[curr_path[curr_level]][curr_path[0]] != 0) {
                int curr_res = curr_weight + adj[curr_path[curr_level]][curr_path[0]];
                if (curr_res < final_res) {
                    copyToFinal(curr_path);
                    final_res = curr_res;
                }
            }
            continue;
        }

        for (int i = 0; i < N; i++) {
            if (adj[curr_path[curr_level]][i] != 0 && !visited[i]) {
                int temp_weight = curr_weight + adj[curr_path[curr_level]][i];
                int temp_bound = curr_bound;
                temp_bound -= ((firstMin(adj, curr_path[curr_level]) + firstMin(adj, i)) / 2);

                if (temp_bound + temp_weight < final_res) {
                    curr_path[curr_level + 1] = i;
                    visited[i] = true;

                    Node new_node;
                    new_node.level = curr_level + 1;
                    new_node.curr_weight = temp_weight;
                    new_node.curr_bound = temp_bound;
                    memcpy(new_node.curr_path, curr_path, sizeof(curr_path));
                    memcpy(new_node.visited, visited, sizeof(visited));
                    q.push(new_node);

                    visited[i] = false;
                }
            }
        }
    }
}

int main() {
    int adj[N][N] = {{0, 10, 15, 20},
                     {10, 0, 35, 25},
                     {15, 35, 0, 30},
                     {20, 25, 30, 0}};

    TSP(adj);

    printf("Minimum cost: %d\n", final_res);
    printf("Path Taken: ");
    for (int i = 0; i <= N; i++) {
        printf("%d ", final_path[i]);
    }

    return 0;
}
