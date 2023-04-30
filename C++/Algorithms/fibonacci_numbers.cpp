//
// Created by 김지민 on 2023/04/28.
//

/*
 * Fibonacci problem
 *
 * 1. Design:
 *      Design Approach: DP(Dynamic Programming)
 *      Step 1. derive recurrence equation
 *          f(n) = f(n-1) + f(n-2)
 *      Step 2. bottom up save and reuse
 *
 */

/*
 * 2. Implementation
 */
#include <iostream>
using namespace std;

int fib(int n) {
    int f[n+2];
    int i;

    f[0] = 0;
    f[1] = 1;

    for (i = 2; i <= n; i++) {
        f[i] = f[i - 1] + f[i -2]; // homogeneous linear recurrence.
    }

    return f[n];
}

int main() {
    int n = 9;
    cout << fib(n);
    return 0;
}

/*
 * 3. Analysis
 *
 * T(n) = T(n-1) + T(n-2)
 */