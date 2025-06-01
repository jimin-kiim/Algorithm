//
// Created by 김지민 on 2/26/24.
//
#include <bits/stdc++.h>
using namespace std;

int permutation[8];
int n, m;

void func(int k) { // meaning: the sequence is filled out upto kth index.
    // termination condition
    if (k == m) { // when a sequence is built upto mth index, when it reached the leaf node, exit the function.
        for (int i = 0; i < m; i++) {
            cout << permutation[i] << " "; // printing out the built permutation.
        }
        cout << "\n";
        return;
    }

    // selecting subsequent elements
    for (int i = 1; i <= n; i++) {
        // promising function - blank.
        // building a solution
        permutation[k] = i; // set the number i as the kth number of the sequence.
        // recurrence
        func(k + 1); // build the item of the sequence, setting (k+1)th index of the it.
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m; // n: the number of the items that would be used to build a sequence, m: the length of the sequence to be made up.
    func(0); // it means that the sequence is filled out upto 0 index.
}

/*
 * permutation, duplication of possible numbers allowed, ascending order
 */