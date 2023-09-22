//
// Created by 김지민 on 2023/09/22.
//
#include <bits/stdc++.h>
using namespace std;

#define MAX 1000001
int palette[MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long mi, ma;
    cin >> mi >> ma;

    for (int i = 2; i <= 1000000; i++) {
        long long exp = pow(i, 2);
        for (int j = 1; exp * j <= ma; j++) {
            if (exp * j >= mi) palette[exp * j - mi] = 1;
        }
    }

    int count = 0;
    for (long long i = mi; i <= ma; i++) {
        if (palette[i - mi] == 0) count++;
    }
    cout << count;
}

// 4, 9, 25, 49, 121, 169, 17^2, 19^2, 23^2, .... 소수의 제곱