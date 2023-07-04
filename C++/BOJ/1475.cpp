//
// Created by 김지민 on 2023/07/04.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int freq[10] = {};
    cin >> n;
    while (n > 0) {
        freq[n%10]++;
        n /= 10;
    }

    if((freq[6] + freq[9])%2) {
        freq[6] = (freq[6] + freq[9] - 1) / 2;
        freq[9] = freq[6] + 1;
    } else {
        freq[6] = freq[9] = (freq[6] + freq[9]) / 2;
    }

    int max = 0;
    for (int i : freq) {
        if (i > max) max = i;
    }
    cout << max;
}