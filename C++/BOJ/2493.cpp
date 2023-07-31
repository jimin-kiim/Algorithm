//
// Created by 김지민 on 2023/07/30.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> towers;

    for (int i = 0; i < n; i++) {
        int height;
        cin >> height;
        towers.push_back(height);
        bool found = false;
        for (int j = i; j >= 0; j--) {
            if (towers[j] > height) {
                cout << j + 1 << " ";
                found = true;
                break;
            }
        }
        if (!found) cout << 0 << " ";
    }
}

/*
 * 각 탑. 왼쪽 방향으로 차례로 순회. 본인 높이보다 높으면서 가장 먼저 발견되는 탑
 * -> 시간 초과
 * 
 */