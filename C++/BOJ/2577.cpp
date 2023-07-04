//
// Created by 김지민 on 2023/07/04.
//


#include <bits/stdc++.h>
using namespace std;

int frequency[10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c, d;
    cin >> a >> b >> c;
    d = a * b * c;

#if false
    /**
     * solution 1
     * - to_string
     * - ascii
     */

    string result = to_string(d);

    for (char c : result) {
        frequency[c-'0'] += 1;
    }
#else
    /**
     * solution 2
     * using int itself
     */

    while(d > 0) {
        frequency[d%10]++;
        d /= 10;
    }
#endif

    for (int i = 0; i < 10; i++) {
        cout << frequency[i] << "\n";
    }
}