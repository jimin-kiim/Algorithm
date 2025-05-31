//
// Created by 김지민 on 3/7/24.
//
#include <bits/stdc++.h>
using namespace std;

int n, m;
int res_indices[8];
int palette[8];

// overall structure is similar to the no.15651 but the numbers traversed in for-statement are the indices, not the actual values that would be used for creating the permutation.
void func(int k) {
    // termination condition
    if (k == m) { // when the mth element is set, when it reached the leaf node, exit the function.
        for (int i = 0; i < m; i++) {
            cout << palette[res_indices[i]] << " "; // printing out the corresponding elements by mapping the index value to the actual value using the palette array.
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        // building a solution
        res_indices[k] = i; // record that ith element in the palette would be used as a kth element of the sequence.
        // recurrence
        func(k + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> palette[i]; // the elements that would be used to build a sequence is given.
    }

    sort(palette, palette + n); // sort the elements of the palette. in order to print the sequences in ascending order.
    func(0);
}
/*
 * permutation, duplication of possible numbers is allowed, ascending order
 */