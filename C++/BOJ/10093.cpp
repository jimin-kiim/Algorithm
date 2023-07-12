//
// Created by 김지민 on 2023/07/12.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
//    int input[2];
    long long input[2];
    cin >> input[0] >> input[1];
    sort(input, input + 2);
    if (input[0] == input[1]) {
        cout << 0 << "\n";
    } else {
        cout << input[1] - input[0] - 1 << "\n";
    }

//    for (int i = input[0] + 1; i < input[1]; i++ )
    for (long long i = input[0] + 1; i < input[1]; i++ )
        cout << i << " ";
}