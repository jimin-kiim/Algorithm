//
// Created by 김지민 on 2023/04/28.
//

/*
 * Binomial Coefficient
 *
 * 1. Design:
 *      Design Approach: DP(Dynamic Programming)
 *      Step 1. derive recurrence equation
 *              (n, k) = (n-1, k-1) + (n-1, k)
 *      Step 2. bottom up save and reuse
 *
 */

/*
 * 2. Implementation
 */
#include <iostream>
using namespace std;

int min(int a, int b);

int binomialCoeff(int n, int k) {
    int C[n + 1][k + 1];
    int i, j;

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= min(i,k); j++) {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
    return C[n][k];
}

int min(int a, int b) { return (a < b) ? a : b; }

int main() {
    int n = 5, k = 2;
    cout << "Value of C[" << n << "][" << k << "] is " << binomialCoeff(n, k);
}

/*
 * 3. Analysis
 *
 * T(n, k) = 1 + 2  + 3 + … + k + (k +1) * (n- k + 1)
 *         = k(k+1) /2 + (k +1) * (n- k + 1)
 *         = (2n -k + 2)(k+1)/2
 *         <= O(nk)
 */