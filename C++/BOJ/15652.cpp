//
// Created by 김지민 on 2/26/24.
//
#include <bits/stdc++.h>
using namespace std;

int res[9];
int n, m;

// same structure with 15651.cpp but the difference is in setting the next element for the sequence.
// since the next element should not be smaller than the number used right before, when selecting the next element for the sequence,
// it should start from the element that is used right before in the palette for the creating the sequence.
void func(int start, int k) {
    // termination condition
    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
        return;
    }

    // selecting subsequent elements
    for (int i = start; i <= n; i++) {
        // building a solution
        res[k] = i;
        // recurrence
        func(i, k + 1); // saying that it should start from the element used right now in the palette for building a sequence.
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    func(1, 0);
}

/*
 * combination, duplication of possible numbers allowed, ascending order
 */