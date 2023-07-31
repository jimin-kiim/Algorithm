//
// Created by 김지민 on 2023/07/30.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, height;
    cin >> n;
    stack<int> towers;
    int max = 0;

    for (int i = 0; i < n; i++) {
        cin >> height;
        if (!i) {
            cout << 0 << " ";
        } else {
            cout << max << " ";
            if (towers.top() < height) {
                max = i + 1;
            }
        }
        towers.push(height);
    }
}

/*
 * 각 탑. 왼쪽 방향으로 차례로 순회. 본인 높이보다 높으면서 가장 먼저 발견되는 탑 찾기
 * -> 시간 초과
 *
 * 바로 직전 높이보다 방금 들어온 높이가 더 크면 max 값을 현재 값으로 변경
 * max - 1 값. 타워 번호 출력
 * -> 시간 초과
 */