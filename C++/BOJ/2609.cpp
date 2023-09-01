//
// Created by 김지민 on 2023/08/18.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    int gcd = 1, lcm;
    for (int i = min(a,b); i >= 1; i--) {
        if (a % i == 0 && b % i == 0) {
            gcd = i;
            break;
        }
    }
    lcm = a * b / gcd;
    cout << gcd << "\n" << lcm;
}