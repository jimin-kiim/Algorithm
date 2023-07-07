//
// Created by 김지민 on 2023/07/08.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    for (int i = 0; i < 3; i++) {
        int count = 0;
        for (int j = 0; j < 4; j++) {
            int input = 0;
            cin >> input;
            if (input) count++;
        }
        if (count == 4) {
            cout << "E\n";
        } else if (count == 3) {
            cout << "A\n";
        } else if (count == 2) {
            cout << "B\n";
        } else if (count == 1) {
            cout << "C\n";
        } else {
            cout << "D\n";
        }
    }
}