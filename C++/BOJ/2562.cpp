//
// Created by 김지민 on 2023/07/13.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int input;
    int max = 0;
    int max_index = 0;
    for (int i = 0; i < 9; i++) {
        cin >> input;
        if (input > max) {
            max = input;
            max_index = i + 1;
        }
    }
    cout << max << "\n";
    cout << max_index << "\n";
}