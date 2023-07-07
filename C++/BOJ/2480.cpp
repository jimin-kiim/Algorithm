//
// Created by 김지민 on 2023/07/07.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int input[3];
    for (int i = 0; i < 3; i ++) {
        cin >> input[i];
    }
    sort(input, input + 3);
    if (input[2] == input[0]) {
        cout << input[0] * 1000 + 10000;
    } else if (input[2] == input[1] || input[1] == input[0]) {
        cout << input[1] * 100 + 1000;
    } else {
        cout << input[2] * 100;
    }
}