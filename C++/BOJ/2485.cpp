//
// Created by 김지민 on 2/13/24.
//
#include <bits/stdc++.h>
using namespace std;

// a < b
int calculate_gcd(int a, int b) {
    if (a == 0) return b; // GCD(0, A) = A
    return calculate_gcd(b % a, a); // GCD(A, B) = GCD(r, A)
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int start, prev, gcd;

    cin >> start >> prev;
    gcd = prev - start;

    for (int i = 2; i < n; i++) {
        int input;
        cin >> input;
        gcd = calculate_gcd(gcd, input - prev);
        prev = input;
    }

    cout << (prev - start) / gcd - n + 1;
}

/*
 * 1, 3, 7, 13
 * -> dis: 2, 4, 6
 * -> 최대 공약수 : 2
 * -> 0, 1, 2
 *
 * sum (2 / 2 - 1, 4 / 2 - 1, 6 / 2 - 1)
 * -> 3
 * -> (last - first) / gcd - n + 1
 *
 * dis: 2, 3, 6
 * -> 최대 공약수: 1
 * -> 1, 2, 5
 */

/*
 * Euclidean Algorithm
 *
 * A = aG, B = bG (a < b)
 * bG = aGq + r
 * r = (b - aq)G
 *
 * GCD(A, B) = (r, A)
 */