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
        for (int j = 0; j < i; j++) cout << " "; // 0 <= j < n - 2
        for (int j = 2 * (n - i) - 1; j > 0; j--) cout << "*";
        cout << "\n";
    }

    // 한 줄
    for (int i = 0; i < n - 1; i++) cout << " ";
    cout << "*\n";

    // n - 1 줄
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i - 1; j++) cout << " "; //  0 <= j < n - 2
        for (int j = 0; j < 2 * (n - i) + 1; j++) cout << "*";
        cout << "\n";
    }
}