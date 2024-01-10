//
// Created by 김지민 on 1/10/24.
//
#include <bits/stdc++.h>
using namespace std;

int recursive_function(int a, int b, int c, int count, int result);

int main() {
    ios:: sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    int result = recursive_function(a, b, c, 1, a);
    cout << result;
}

int recursive_function(int a, int b, int c, int count, int result) {
    if (count >= b)
        return result;
    result *= a;
    if (result >= c)  result %= c;
    return recursive_function(a, b, c, ++count, result);
}


/*
 * 10 ^ 11 % c = d
 * 10 ^ 11  = x * c + d
 *
 * 2 ^ 4 % 3
 * 2 * 2* 2* 2 = 5 * 3 + 1
 */