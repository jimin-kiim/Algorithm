//
// Created by 김지민 on 2023/08/01.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    long long count = 0;
    int buildings[n];
    for (int i = 0; i < n; i++) {
         cin >> buildings[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (buildings[i] > buildings[j]) count++;
            else break;
        }
    }
    cout << count;
}

/*
 * 본인 이후에 들어오는 값들 중 본인보다 크거나 같은 값이 들어오기 전까지의 개수 카운팅.
 * -> 시간 초과
 *
 *
 */