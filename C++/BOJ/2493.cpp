//
// Created by 김지민 on 2023/07/30.
//
#include <bits/stdc++.h>
using namespace std;

#define H first
#define I second
#define MAX 100000001

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, height;
    cin >> n;
    stack<pair<int, int> > towers;
    towers.push({MAX, 0});
    for (int i = 0; i < n; i++) {
        cin >> height;
        while (towers.top().H < height) {
            towers.pop();
        }
        cout << towers.top().I;
        if (i != n - 1) cout << " ";
        towers.push({height, i + 1});
    }
}

/*
 * 각 탑. 왼쪽 방향으로 차례로 순회. 본인 높이보다 높으면서 가장 먼저 발견되는 탑 찾기
 * -> 시간 초과
 *
 * max_height보다 큰 높이가 들어오면 max 값을 현재 값으로 변경
 * max - 1 값. 타워 번호 출력
 * -> 시간 초과
 *
 * 방금 들어온 높이 값보다 작은 탑들의 높이의 영향은 이제 무의미해진다.
 * (이후에 어떤 탑이 들어와도 방금 들어온 높이 값보다 작은 탑들에는 이제 신호가 닿을 일이 없다.)
 * 방금 들어온 높이 값보다 큰 탑의 영향은 아직은 유의미하다.
 * 그러므로 전자에 해당하는 탑들은 pop하며 후자를 찾아 가도 된다.
 * 후자가 레이저 신호를 수신할 탑. (해당 탑보다 왼쪽에 위치하는 탑들 중 가장 먼저 발견되는 해당 탑보다 큰 탑)
 *
 */