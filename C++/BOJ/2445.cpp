//
// Created by 김지민 on 1/18/24.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    // n - 1 줄
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < i + 1; j++) { // i + 1 만큼
            cout << "*";
        }
        for (int j = 0; j < (n - i - 1) * 2; j++) {
            cout << " ";
        }
        for (int j = 0; j < i + 1; j++) {
            cout << "*";
        }
        cout << "\n";
    }

    // 한 줄
    for (int i = 0; i < n * 2; i++) {
        cout << "*";
    }
    cout << "\n";

    // n - 1 줄
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            cout << "*";
        }
        for (int j = 0; j < (n - i) * 2; j++) {
            cout << " ";
        }
        for (int j = 0; j < i; j++) {
            cout << "*";
        }
        cout << "\n";
    }
}