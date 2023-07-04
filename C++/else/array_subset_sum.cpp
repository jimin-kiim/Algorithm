//
// Created by 김지민 on 2023/07/04.
//

#include <bits/stdc++.h>
using namespace std;

int occurence[100];

int verifier(int arr[], int N) {
    for (int i = 0; i < N; i++) {
        if (occurence[100 - arr[i]]) {
            return 1;
        }
        occurence[arr[i]] = 1;
    }
    return 0;
}

int main() {
    int arr[] = {1, 52, 48};
    cout << verifier(arr, sizeof arr / arr[0]) << " ";
    int arr2[] = {50, 42};
    cout << verifier(arr2, sizeof arr2 / arr2[0]) << " ";
    int arr3[] = {4, 13, 63, 87};
    cout << verifier(arr3, sizeof arr3 / arr3[0]) << " ";
}

/*
 * TC: O(N)
 */