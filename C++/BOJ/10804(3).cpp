//
// Created by 김지민 on 2023/07/12.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[21];
    for (int i = 1; i < 21; i++) {
        arr[i] = i;
    }

    for (int i = 0; i < 10; i++) {
        int a, b;
        cin >> a >> b;
        reverse (arr + a, arr + b + 1);
    }

    for (int i = 1; i < 21; i++) {
        cout << arr[i] << " ";
    }
}