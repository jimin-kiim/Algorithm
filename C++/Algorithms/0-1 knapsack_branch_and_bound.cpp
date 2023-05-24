//
// Created by 김지민 on 2023/05/17.
//

/*
 * 0/1 Knapsack Problem
 * S = {item_1, item_2, ..., item_n} // objects
 *  w_i = {weight_1, weight_2, ..., weight_n} // attribute1 of object
 *  p_i = {profit_1, profit_2, ..., profit_n} // attribute2 of object
 *  W = sack size // constraint value for one of attributes of object
 *  find A (a subset of S) such that
 *      1) maximize the profits in A
 *      2) sum of the weights in A <= W
 *  constraint optimization problem. (constrained combinational optimization problem)
 *
 *  1. Design:
 *      Design Approach: Branch and Bound(BFS)
 *      Step 1. design promising Function
 *      Step 2. BFS traverse, visit
 */

/*
 * 2. Implementation
 */
#include <iostream>
#include <queue>
using namespace std;

struct Item {
    float weight;
    int value;
};

struct Node {
    int level, profit, bound;
    float weight;
};

bool cmp(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

int bound(Node u, int n, int W, Item arr[]) {
    if (u.weight >= W) {
        return 0;
    }

    int profit_bound = u.profit;

    int j = u.level + 1;
    int totweight = u.weight;

    while ((j < n) && (totweight + arr[j].weight <= W)) {
        totweight += arr[j].weight;
        profit_bound += arr[j].value;
        j++;
    }

    if (j < n) {
        profit_bound += (W - totweight) * arr[j].value / arr[j].weight;
    }

    return profit_bound;
}

int knapsack(int W, Item arr[], int n) {
    sort(arr, arr + n, cmp);
    queue<Node> Q;
    Node u, v;

    u.level = -1;
    u.profit = u.weight = 0;
    Q.push(u);

    int maxProfit = 0;
    while (!Q.empty()) {
        u = Q.front();
        Q.pop();

        if (u.level == -1) {
            v.level = 0;
        }

        if (u.level == n - 1) {
            continue;
        }

        v.level = u.level + 1;
        v.weight = u.weight + arr[v.level].weight;
        v.profit = u.profit + arr[v.level].value;

        if (v.weight <= W && v.profit > maxProfit) {
            maxProfit = v.profit;
        }

        v.bound = bound(v, n, W, arr);

        if (v.bound > maxProfit) {
            Q.push(v);
        }

        v.weight = u.weight;
        v.profit = u.profit;
        v.bound = bound(v, n, W, arr);
        if (v.bound > maxProfit) {
            Q.push(v);
        }
    }
    return maxProfit;
}

int main() {
    int W = 10;
    Item arr[] = {{2, 40}, {3.14, 50}, {1.98, 100}, {5, 95}, {3, 30}};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum possible profit = " << knapsack(W, arr, n);

    return 0;
}