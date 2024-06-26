//
// Created by 김지민 on 1/20/24.
//
#include <bits/stdc++.h>
using namespace std;

void print(int x, int y, int size);
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            print(i, j, n);
        }
        cout << "\n";
    }
}

void print(int x, int y, int size) {
    if ((x / size) % 3 == 1 && (y / size) % 3 == 1) { // 종료 조건 1 (최소 단위 여부와 상관 없는 종료 조건)
        cout << " ";
        return;
    }
    if (size == 1) { // 종료 조건 2 (최소 단위 도달 시)
        cout << "*";
        return;
    }

    // 최소 단위 도달을 위한 재귀 호출
    size /= 3;
    print(x, y, size);
}