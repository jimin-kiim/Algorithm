//
// Created by 김지민 on 1/31/24.
//
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

//int board[100002];
int t[100002];

//int dir[3] = {};
int n, k;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(t, t + 100002, -1);

    cin >> n >> k;
    queue<int> q;
    q.push(n);
    t[n] = 0;

    while (t[k] == -1) {
        int x = q.front();
        q.pop();

        int nx = x - 1;
        if (t[nx] >= 0) continue;

        q.push(nx);
        t[nx] = t[x] + 1;

        nx = x + 1;
        if (t[nx] >= 0) continue;

        q.push(nx);
        t[nx] = t[x] + 1;

        nx = x * 2;
        if (t[nx] >= 0) continue;

        q.push(nx);
        t[nx] = t[x] + 1;
    }
    cout << t[k];
    cout << "\n";
    for (int i = 0; i < 20; i++)
        cout << i << " ";
    cout << "\n";
    for (int i = 0; i < 20; i++)
        cout << t[i] << " ";
}
/*
 * 5 10 20 19 18 17
 * 5 10 9 18 17
 *
 * 일단 순간이동을 시도해서 n이 k 넘어가면 순간 이동 멈추고 1칸씩 줄이기
 * -> 5 10 20 19 18 17
 * -> 최소 시간 벗어남
 *
 * 미로탐색 문제처럼 각 지점에서의 최소 시간 트래킹해 나가다가
 * k 도달하면 종료
 */