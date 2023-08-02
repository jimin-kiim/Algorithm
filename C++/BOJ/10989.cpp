//
// Created by 김지민 on 2023/08/02.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, input;
    cin >> n;

    int arr[10001] = {};
    for (int i = 0; i < n; i++) {
        cin >> input;
        arr[input] += 1;
    }

    for (int i = 1; i < 10001; i++) {
        int count = arr[i];
        for (int j = 0; j < count; j++) {
            cout << i << "\n";
        }
    }
}