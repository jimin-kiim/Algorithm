//
// Created by 김지민 on 2023/09/22.
//
#include <bits/stdc++.h>
using namespace std;

#define MAX 1000000000000
int  palette[MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 2; i < 1000000; i++) {
        int exp = pow(i, 2);
        for (int j = 1; exp * j <= MAX; j++) {
            palette[exp * j] = 1;
        }
    }

    int mi, ma;
    cin >> mi >> ma;

    int count = 0;
    for (int i = mi; i <= ma; i++) {
        if (palette[i] == 0) count++;
    }
}