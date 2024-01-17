//
// Created by 김지민 on 1/17/24.
//
#include <bits/stdc++.h>
using namespace std;
int arr[130][130];
int result[2];

void recursive_function(int x, int y, int size);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    recursive_function(0, 0, n);
    cout << result[0] << "\n" << result[1];
}

bool is_homogeneous(int x, int y, int size) {
    for(int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (arr[x][y] != arr[x + i][y + j]) return false;
        }
    }
    return true;
}

void recursive_function(int x, int y, int size) {
    if (is_homogeneous(x, y, size) == true) {
        int value = arr[x][y];
        result[value]++;
        return;
    }

    size /= 2;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            recursive_function(x + size * i, y + size * j , size);
        }
    }
}