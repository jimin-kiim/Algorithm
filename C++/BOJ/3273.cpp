//
// Created by 김지민 on 2023/07/04.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n;
    int input[n];
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    cin >> x;

    int count = 0;
    int freq[2000001] = {};
    for (int num : input) {
        if (x - num > 0 && freq[x - num]) {
            count += 1;
        }
        freq[num] = 1;
    }
    cout << count;
}