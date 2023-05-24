//
// Created by 김지민 on 2023/05/21.
//

/*
 * Subset Sum Problem
 * finding subset of elements that are selected from a given set
 * whose sum adds up to a given number K.
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
using namespace std;

bool isSubsetSum(const int set[], int n, int sum) {
    bool subset[n + 1][sum + 1];
    // subset[i][j]: whether there exists a subset of the elements
    //               set[0] to set[i-1] that can achieve a sum of j

    for (int i = 0; i <= n; i++) {
        subset[i][0] = true; // if the target sum is 0
        // it's always possible to form an empty subset with a sum of 0
    }

    for (int i = 1; i <= sum; i++) {
        subset[0][i] = false; // target sum is non-zero, set is empty
        // emtpy set cannot make non-zero sum
    }

    // filling the subset table in bottom up manner
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < set[i - 1]) { // current element is greater than the target sum
                subset[i][j] = subset[i - 1][j]; // without including the current element
            }

            if (j >= set[i - 1]) { // current element can be included
                subset[i][j] = subset[i - 1][j] || subset[i - 1][j - set[i - 1]];
            }
        }
    }
    return subset[n][sum];
}

int main() {
    int set[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);
    if (isSubsetSum(set, n, sum)) {
        cout << "Found a subset with given sum";
    } else {
        cout << "No subset with given sum";
    }

    return 0;
}

/*
 * sum: 9
 *
 * 1 0 0 0 0 0 0 0 0 0
 * 1 0 0 1 0 0 0 0 0 0 (3)
 * 1 0 0 1 0 0 0 0 0 0 (34)
 * 1 0 0 1 1 0 0 1 0 0 (4)
 * 1 0 0 1 1 0 0 1 0 0 (12)
 * 1 0 0 1 1 1 0 1 1 1 (5)
 * 1 0 1 1 1 1 1 1 1 1 (2)
 *
 */