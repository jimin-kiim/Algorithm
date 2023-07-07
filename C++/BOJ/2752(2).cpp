//
// Created by 김지민 on 2023/07/07.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[3];
    int min_value, max_value;
    for (int i = 0; i < 3; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+3);
    cout << arr[0] << " " <<  arr[1] << " " << arr[2];
}