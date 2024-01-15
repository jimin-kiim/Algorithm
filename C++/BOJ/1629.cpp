//
// Created by 김지민 on 1/10/24.
//
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll recursive_function(int b, int e, int m);

int main() {
    ios:: sync_with_stdio(0);
    cin.tie(0);

    int base, exp, mod;
    cin >> base >> exp >> mod;
    int result = recursive_function(base, exp, mod);
    cout << result;
}

ll recursive_function(int b, int e, int m) {
    if (e == 1) return b % m;
    ll temp = recursive_function(b, e / 2, m);
    temp = temp * temp % m;
    if (e % 2 == 0) return temp;
    return temp * b % m;
}

/* 6 11 13
 * 6 36->10 60->8 48->9 54->2 12 72->7 ... ? ?
 *
 * 10 ^ 11 % c = d
 * 10 ^ 11  = x * c + d
 * 10 ^ 5.5 * 10 ^ 5.5  ..?? (X)
 * 10 ^ 5 * 10 ^ 5 * 10
 * 10 ^ 2 * 10 ^ 2 * 10 ...
 *
 * 2 ^ 4 % 3
 * 2 ^ 2 * 2 ^ 2
 * 2 * 2 * 2 * 2 = 1 * 1
 * => 반을 나눠서. b가 1이 될 때까지 나눠서. 곱하고 modulo 구하고 그 결과값들끼리 곱한다.
 *
 * 4 1 2
 * b가 1이면 a % c
 *
 * 경계값 꼭 점검하기
 */