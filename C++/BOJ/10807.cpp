//
// Created by 김지민 on 2023/07/05.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, v;
    cin >> n;
    int arr [n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> v;

    int count = 0;
    for (int e : arr) {
        if (e == v) count++;
    }
    cout << count;
}