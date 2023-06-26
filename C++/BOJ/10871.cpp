//
// Created by 김지민 on 2023/06/26.
//
/**
* input:
 * 1. N, X
 * 2. A: N number of integers
 *
 * output:
 * printing B = {x|x<X, x in A}
 * B isn't empty
*/

#include <bits/stdc++.h>
using namespace std;

int n, x, a[10005]; // goal for PS: not writing a clean code.
// it's solving the problem as fast as possible in the limited time
int main () {
    ios::sync_with_stdio(0); // in fact, the arg type should be bool.
    // but for PS, it doesn't matter
    cin.tie(0);
    cin >> n >> x;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        if (a[i] < x) {
            cout << a[i] << " ";
        }
    }
}
