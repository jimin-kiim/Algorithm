//
// Created by 김지민 on 2023/07/11.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int min = 100;
    int sum = 0;
    for (int i = 0; i < 7; i++) {
        int input;
        cin >> input;
        if (input %2) {
            sum += input;
            if (input < min) {
                min = input;
            }
        }
    }
    if (sum == 0) {
        cout << -1;
    } else {
        cout << sum << "\n" << min;
    }
}