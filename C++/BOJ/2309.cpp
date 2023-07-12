//
// Created by 김지민 on 2023/07/11.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int inputs[9];
    int sum = 0;
    int input;
    for (int i = 0; i < 9; i++) {
        cin  >> input;
        inputs[i] = input;
        sum += input;
    }
    int target = sum - 100;
    int occur[101] = {};
    int not_found = true;
    for (int i = 0; i < 9; i++) {
        if(not_found && occur[target-inputs[i]]) {
            occur[inputs[i]] = occur[target - inputs[i]] = 0;
            not_found = false;
        } else {
            occur[inputs[i]] = 1;
        }

    }
    for (int i = 1; i <101; i++) {
        if (occur[i]) cout << i << "\n";
    }
}