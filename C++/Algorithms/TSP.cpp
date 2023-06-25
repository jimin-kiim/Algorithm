//
// Created by 김지민 on 2023/06/07.
//
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 1e9;

// Structure to represent a node in the search tree
struct Node {
    int level;
    int cost;
    vector<int> path;
};

// Custom comparator for priority queue
struct Comp {
    bool operator()(const Node& lhs, const Node& rhs) const {
        return lhs.cost > rhs.cost;
    }
};

// Function to calculate the lower bound (cost) of a node
int calculateCost(vector<vector<int> >& graph, const Node& node) {
    int lowerBound = 0;

    // Include the cost of the edges in the path
    for (int i = 0; i < node.level - 1; i++) {
        lowerBound += graph[node.path[i]][node.path[i + 1]];
    }

    // Find the minimum outgoing edge from the last node in the path
    int lastNode = node.path.back();
    int minOutgoingEdge = INF;
    for (int i = 0; i < graph.size(); i++) {
        if (i != lastNode) {
            minOutgoingEdge = min(minOutgoingEdge, graph[lastNode][i]);
        }
    }

    // Add the minimum outgoing edge cost to the lower bound
    lowerBound += minOutgoingEdge;

    return lowerBound;
}

// Function to solve the TSP using Branch and Bound with BFS
int solveTSP(vector<vector<int> >& graph) {
    int n = graph.size();

    // Create a priority queue for the search tree nodes
    priority_queue<Node, vector<Node>, Comp> pq;

    // Create the initial node with level 0 (starting from the first node)
    Node initialNode;
    initialNode.level = 1;
    initialNode.cost = 0;
    initialNode.path.push_back(0);
    pq.push(initialNode);

    int minCost = INF;

    while (!pq.empty()) {
        // Get the node with the minimum cost from the priority queue
        Node currentNode = pq.top();
        pq.pop();

        // If the level is equal to the number of nodes, we have completed a full tour
        if (currentNode.level == n) {
            // Add the cost of the last edge to return to the starting node
            currentNode.cost += graph[currentNode.path.back()][0];

            // Update the minimum cost
            minCost = min(minCost, currentNode.cost);
        }

        // Generate child nodes by considering all unvisited cities
        for (int i = 1; i < n; i++) {
            if (find(currentNode.path.begin(), currentNode.path.end(), i) == currentNode.path.end()) {
                // Create a new node for the child
                Node childNode;
                childNode.level = currentNode.level + 1;
                childNode.cost = currentNode.cost + graph[currentNode.path.back()][i];
                childNode.path = currentNode.path;
                childNode.path.push_back(i);

                // Calculate the lower bound (cost) for the child node
                childNode.cost += calculateCost(graph, childNode);

                // If the lower bound is less than the current minimum cost, add the child node to the priority queue
                if (childNode.cost < minCost) {
                    pq.push(childNode);
                }
            }
        }
    }

    return minCost;
}

int main() {
    // Example graph representing distances between cities
    vector<vector<int> > graph;
    graph = {{0, 10, 15, 20},
            {10, 0, 35, 25},
            {15, 35, 0, 30},
            {20, 25, 30, 0}};

    int minCost = solveTSP(graph);

    cout << "Minimum cost of the TSP tour: " << minCost << endl;

    return 0;
}
