//
// Created by 김지민 on 1/17/24.
//
#include <bits/stdc++.h>
using namespace std;
int arr[65][65];
string result = "";

void recursive_function(int x, int y, int size);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        for (int j = 0; j < n; j++) {
            int modulo = pow(10, n - j - 1);
            int bit = input / modulo;
            arr[i][j] = bit;
            input %= modulo;
        }
    }

    recursive_function(0, 0, n);
    cout << result;
}

bool is_homogeneous(int x, int y, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (arr[x][y] != arr[x + i][y + j]) return false;
        }
    }
    return true;
}

void recursive_function(int x, int y, int size) {
    if (is_homogeneous(x, y, size) == true) {
        result += to_string(arr[x][y]);
        return;
    }

    size /= 2;
    result += "(";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            recursive_function(x + size * i, y + size * j, size);
        }
    }
    result += ")";
}