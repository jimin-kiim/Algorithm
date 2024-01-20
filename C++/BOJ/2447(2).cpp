//
// Created by 김지민 on 1/20/24.
//
#include <bits/stdc++.h>
using namespace std;

void print(int x, int y, int size);
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            print(i, j, n);
        }
        cout << "\n";
    }
}

void print(int x, int y, int size) {
    if ((x / size) % 3 == 1 && (y / size) % 3 == 1) {
        cout << " ";
        return;
    }
    if (size == 1) {
        cout << "*";
        return;
    }

    size /= 3;
    print(x, y, size);
}

void recursive_function(int x, int y, int size) {
    if ((x / size) % 3 == 1 && (y / size) % 3 == 1) cout << " ";
    if (size == 1) {
        cout << "*";
        if (x == n - 1) cout << "\n";
        return;
    }

    size /= 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            recursive_function(x + size * i, y + size * j, size);
        }
    }
}