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
        for (int j = 0; j < (b - a + 1) / 2; j++) {
            swap(arr[a+j], arr[b-j]);
            // arr[a++], arr[b--] -> (b - a + 1) is also modified
        }
    }

    for (int i = 1; i < 21; i++) {
        cout << arr[i] << " ";
    }
}