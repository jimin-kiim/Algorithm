//
// Created by 김지민 on 2023/05/16.
//

/*
 * 0/1 Knapsack Problem
 *  S = {item_1, item_2, ..., item_n} // objects
 *  w_i = {weight_1, weight_2, ..., weight_n} // attribute1 of object
 *  p_i = {profit_1, profit_2, ..., profit_n} // attribute2 of object
 *  W = sack size // constraint value for one of attributes of object
 *  find A (a subset of S) such that
 *      1) maximize the profits in A
 *      2) sum of the weights in A <= W
 *  constraint optimization problem. (constrained combinational optimization problem)
 *
 * 1. Design:
 *      Design Approach: DP(Dynamic Programming)
 *      Step 0. examples (guessing)
 *      Step 1. derive recurrence equation
 *      Step 2. bottom up save and reuse
 */

/*
 * 2. Implementation
 */

#include <iostream>
#include <vector>
using namespace std;

// utility function
int max(int a, int b) {return (a > b) ? a : b;}

int knapSack(int W, int wt[], int val[], int n) {
    int i, w;
    vector<vector<int> > K(n + 1, vector<int>(W + 1));

    // building a lookup table in bottom up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                K[i][w] = 0;
            } else if (wt[i - 1] <= w) {
                K[i][w] = max(val[i - 1] + K[i - 1][w-wt[i - 1]], K[i - 1][w]);
            } else {
                K[i][w] = K[i - 1][w];
            }
        }
    }
    return K[n][W];
}

int main() {
    int profit[] = {60, 100, 120};
    int weight[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(profit) / sizeof(profit[0]);

    cout << knapSack(W, weight, profit, n);

    return 0;
}