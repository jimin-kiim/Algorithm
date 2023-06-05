//
// Created by 김지민 on 2023/05/15.
//

/*
 * Subset Sum Problem
 * finding subset of elements that are selected from a given set
 * whose sum adds up to a given number K.
 *
 * 1. Design:
 *      Design Approach: Backtracking(DFS)
 *      Step 1. designing promising function
 *              1) in i_th level, weight + weight(i+1) > W
 *              2) weight + total sum of remaining weights < W
 *              if either 1) or 2) satisfied, stop.
 *      Step 2. DFS traverse, visit
 */

/*
 * 2. Implementation
 */
#include <iostream>
using namespace std;

#define ARRAYSIZE(a) (sizeof(a)) / (sizeof(a[0]))
static int total_nodes;

void printSubset(int A[], int size) {
    for (int i = 0; i < size; i++) {
        cout <<" "<< A[i];
    }
    cout << "\n";
}

int comparator (const void *pLhs, const void *pRhs) {
    int *lhs = (int *)pLhs;
    int *rhs = (int *)pRhs;
    return (*lhs > *rhs) ? 1 : ((*lhs < *rhs) ? -1 : 0);
}

void subset_sum(int input[], int subset[],
                int input_size, int subset_size,
                int sum, int idx,
                int const target_sum) {
    total_nodes++; // keep track the number of total nodes generated

    if (target_sum == sum) { // valid subset is found
        printSubset(subset, subset_size);

        if (idx + 1 < input_size &&
            sum - input[idx] + input[idx + 1] <= target_sum) { // check if creating new subset is possible
            subset_sum(input, subset, input_size, subset_size - 1, sum - input[idx], idx + 1, target_sum);
        }
        return;
    } else {
        if (idx < input_size && sum + input[idx] <= target_sum) { // didn't reach the leaf node yet && available to continue
            for( int i = idx; i < input_size; i++) {
                subset[subset_size] = input[i];
                if (sum + input[i] <= target_sum ) {
                    subset_sum(input, subset, input_size, subset_size + 1, sum + input[i], i + 1, target_sum);
                }
            }
        }
    }
}

void generateSubsets(int input[], int size, int target_sum) {
    int *subset = (int *)malloc(size * sizeof(int));
    int total = 0;

    qsort(input, size, sizeof(int), &comparator);
    for (int i = 0; i < size; i++) {
        total += input[i];
    }

    if (input[0] <= target_sum && total >= target_sum) {
        subset_sum(input, subset, size, 0, 0, 0, target_sum);
    }

    free(subset);
}

int main() {
//    int weights[] = {15, 22, 14, 26, 32, 9, 16, 8 };
//    int target = 53;
    int weights[] = {3, 4, 5, 6};
    int target = 13;
    int size = ARRAYSIZE(weights);
    generateSubsets(weights, size, target);
    cout << "Nodes generated " << total_nodes;
    return 0;
}
