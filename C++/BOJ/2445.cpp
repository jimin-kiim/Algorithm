//
// Created by 김지민 on 1/18/24.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    // n - 1 줄
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 1; j <= i; j++) cout << "*";
        for (int j = 1; j <= (n - i) * 2; j++) cout << " ";
        for (int j = 1; j <= i; j++) cout << "*";
        cout << "\n";
    }

    // 한 줄
    for (int i = 0; i < n * 2; i++) cout << "*";
    cout << "\n";

    // n - 1 줄
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) cout << "*";
        for (int j = 1; j <= (n - i) * 2; j++) cout << " ";
        for (int j = 1; j <= i; j++) cout << "*";
        cout << "\n";
    }
}

/*
 * i = 0에서 시작하는 게 별 거 아닌 데도 갑자기 헷갈릴 땐 그냥 눈에 보이는 대로 직관적이게 1부터 하고 <= 쓰기..
 */