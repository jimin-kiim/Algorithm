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
    int max_height = 0;

    for (int i = 0; i < n; i++) {
        cin >> height;
        if (max_height < height) {
            max = i + 1;
            max_height = height;
            cout << 0;
        } else if (towers.top() > height) { // 고쳐야 할 부분.
            // top이 아닐 수도
            cout << i;
        } else {
            cout << max;
        }
        if (i != n - 1) cout << " ";
        towers.push(height);
    }
}

/*
 * 각 탑. 왼쪽 방향으로 차례로 순회. 본인 높이보다 높으면서 가장 먼저 발견되는 탑 찾기
 * -> 시간 초과
 *
 * max_height보다 큰 높이가 들어오면 max 값을 현재 값으로 변경
 * max - 1 값. 타워 번호 출력
 * -> 시간 초과
 */