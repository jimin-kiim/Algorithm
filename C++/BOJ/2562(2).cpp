//
// Created by 김지민 on 2023/07/13.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[9];
    for (int i = 0; i < 9; i++) cin >> arr[i];
    cout << *max_element(arr, arr + 9) << "\n";
    cout << max_element(arr, arr + 9) - arr + 1 << "\n";
}