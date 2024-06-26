//
// Created by 김지민 on 2023/09/01.
//
#include <bits/stdc++.h>
using namespace std;

bool is_primary_number(int n) {
    for (int i = 2; i <= pow(n, 0.5); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int input;
    int cnt = 0;
    while (n--) {
        cin >> input;
        if (input == 1) continue;
        else if (is_primary_number(input)) cnt++;
    }
    cout << cnt;
}