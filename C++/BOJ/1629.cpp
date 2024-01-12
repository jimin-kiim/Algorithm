//
// Created by 김지민 on 1/10/24.
//
#include <bits/stdc++.h>
using namespace std;

int recursive_function(int count, int result);
int a, b, c;

int main() {
    ios:: sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c;
    int result = recursive_function(1, a);
    cout << result;
}

int recursive_function(int count, int result) {
    if (result >= c) result %= c;
    if (result == 0) return result;
    if (count >= b) return result;
    result *= a;
    return recursive_function(++count, result);
}


/*
 * 10 ^ 11 % c = d
 * 10 ^ 11  = x * c + d
 *
 * 2 ^ 4 % 3
 * 2 * 2* 2* 2 = 5 * 3 + 1
 */