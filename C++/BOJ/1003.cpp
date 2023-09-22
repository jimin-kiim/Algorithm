//
// Created by 김지민 on 2023/09/22.
//
#include <bits/stdc++.h>
using namespace std;

int zero[41];
int one[41];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    zero[0] = 1;
    zero[2] = 1;
    for (int i = 3; i < 41; i++) zero[i] = zero[i - 1] + zero[i - 2];

    one[1] = 1;
    for (int i = 2; i < 41; i++) one[i] = one[i - 1] + one[i - 2];

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        cout << zero[n] << " " << one[n];
        cout << "\n";
    }
}


// fib(3) = fib(2) + fib(1)
//        = fib(1) + fib(0) + fib(1)
//        = 1 + 0 + fib(1)
//        = 1 + fib(1)
//        = 1 + 1
//        = 2

// 1 f(3): 2, f(2): 1, f(1): 1 f(0): 0.. -> DP. table 만들어 놓고 lookup
// 0 f(0): 1, f(1): 0, f(2): 1, f(3): 1,