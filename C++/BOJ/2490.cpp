//
// Created by 김지민 on 2023/07/08.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string res = "DCBAE";
    for (int i = 0; i < 3; i++) {
        int count = 0;
        for (int j = 0; j < 4; j++) {
            int input = 0;
            cin >> input;
            count += input;
        }
        cout << res[count] << "\n";
    }
}