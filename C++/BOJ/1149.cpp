//
// Created by 김지민 on 2/8/24.
//
#include <bits/stdc++.h>
using namespace std;

int cost[1001][3];
int dp[1001][3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> cost[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        dp[0][i] = cost[0][i];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            dp[i][j] = min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) + cost[i][j];
        }
    }
    cout << *min_element(dp[n - 1], dp[n - 1] + 3);
}

/*
 * i - 1이 택한 색 인덱스가
 * 0 이면 1, 2
 * 1 이면 2, 0
 * 2 이면 0, 1
 * -> mod 3
 */

/*
 * dp[0] = *min_element(cost[0], cost[0] + 3)을 생각했었는데
 * 시작을 최솟값 갖는 col로 시작하더라도 최종 누적값은 최솟값이 아닌 col에서 시작했을 때 최소가 될 수도 있기 때문에
 * 일단 모든 dp board를 채우고 마지막 세 누적값 결과 중에서 가장 작은 걸 고르는 걸로 수정
 */