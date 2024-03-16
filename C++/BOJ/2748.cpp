//
// Created by 김지민 on 3/16/24.
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll fib[91];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    cout << fib[n];
}