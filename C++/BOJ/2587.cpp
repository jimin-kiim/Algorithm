//
// Created by 김지민 on 2023/07/11.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[5] = {};
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }
    int sum = accumulate(arr, arr + 5, 0);
    sort(arr, arr + 5);
    int mid = arr[2];
    cout << sum / 5 << "\n" << mid;
}