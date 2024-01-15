//
// Created by 김지민 on 1/10/24.
//
#include <bits/stdc++.h>
using namespace std;

long long recursive_function(int a, int b, int c);

int main() {
    ios:: sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    int result = recursive_function(a, b, c);
    cout << result;
}

long long recursive_function(int a, int b, int c) {
    if (b == 1) return a % c;
    long long temp = recursive_function(a, b / 2, c);
    temp *=temp % c;
    if (b % 2 == 0) return temp;
    return temp * a % c;
}
// 6 36->10 60->8 48->9 54->2 12 72->7

/* 6 11 13
 *
 * 10 ^ 11 % c = d
 * 10 ^ 11  = x * c + d
 * 10 ^ 5.5 * 10 ^ 5.5
 * 10 ^ 2.5 * 10 ^ 2.5
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