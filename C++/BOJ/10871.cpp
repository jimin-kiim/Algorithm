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

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        if (a[i] < x) {
            cout << a[i] << " ";
        }
    }
}
