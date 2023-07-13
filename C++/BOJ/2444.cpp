//
// Created by 김지민 on 2023/07/13.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[9];
    for (int i = 0; i < 9; i++) cin >> arr[i];
    int max = 0;
    int max_index = 0;
    for (int i = 0; i < 9; i++) {
        if (arr[i] > max) {
            max = arr[i];
            max_index = i + 1;
        }
    }
    cout << max << "\n";
    cout << max_index << "\n";
}