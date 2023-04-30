//
// Created by 김지민 on 2023/04/28.
//

/*
 * Chained Matrix Multiplication (CMM)
 *
 * 1. Design:
 *      Design Approach: DP(Dynamic Programming)
 *      Step 0. examples (guessing)
 *      Step 1. derive recurrence equation
 *      Step 2. bottom up save and reuse
 *
 */

/*
 * 2. Implementation
 */
#include <iostream>
using namespace std;

int dp[100][100];

int matrixChainMemoised(int* p, int i, int j) {
    if (i == j) {
        return 0;
    }

    if (dp[i][j] != -1 ) {
        return dp[i][j];
    }

    dp[i][j] = INT_MAX;
    for (int k = i; k < j; k++) {
        dp[i][j] = min(dp[i][j], matrixChainMemoised(p, i, k) + matrixChainMemoised(p, k+1, j) + p[i-1]*p[k]*p[j]);
    }

    return dp[i][j];
}

int MatrixChainOrder(int* p, int n) {
    int i = 1, j = n - 1;
    return matrixChainMemoised(p, i, j);
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    memset(dp, -1, sizeof dp);

    cout << "Minimum order of multiplication is " << MatrixChainOrder(arr, n);
}

/*
 * 3. Analysis
 *
 * T(n) = # of subproblems * time/subproblem
 *      = O(n^2) * theta(k)
 *      = O(n^2) * O(n)
 *      = O(n^3)
 */