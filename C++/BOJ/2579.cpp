//
// Created by 김지민 on 2/8/24.
//
#include <bits/stdc++.h>
using namespace std;

int score[301];
int dp[301];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> score[i];

    dp[1] = score[1];
    dp[2] = score[2] + score[1];
    dp[3] = score[3] + max(score[1], score[2]);

    for (int i = 4; i <= n; i++)

        // 현재 계단의 점수 값 + 둘 중 더 큰 값(바로 전 계단을 밟고 온 경우, 한 칸 띄우고 온 경우)
        //  바로 전 계단을 밟고 온 경우를 dp[i - 1]로 하게 되면 세 계단을 연속해 오는 경우를 포함하게 되기 떄문에
        //  dp[i - 1]이 아닌 score[i - 1] + dp[i - 3]으로 해야 한다.
        dp[i] = score[i] + max(score[i - 1] + dp[i - 3], dp[i - 2]);

    cout << dp[n]; // 마지막 계단에서의 누적 점수 값 출력
}

/*
 * 누적 합, 연산의 연관성 -> dp
 */

/*
 * 시작 계단은 미정
 * dp: 각 계단을 지나갈 경우에, 그 당시 최댓값 점수를 얼마로 갖게 되는지 저장.
 *     최종 점수 산출 때는 해당 계단 지나갈 수도 있고 안 지나갈 수도 있고
 */

/*
 * dp[3] = score[3] + max(dp[1], dp[2]);
 * -> 1, 2, 3 계단을 연속으로 지나는 경우를 누적해 저장하게 된다.
 * -> 세 번째 계단을 지나는 경우라면 첫 번째 계단을 지나고 한 칸 띄우고 온 경우이거나
 *    첫 번째 계단은 지나지 않고 두 번째 계단을 지나고 연속해 세 번째 계단으로 온 경우로 이렇게 둘 중 하나이다.
 * -> 그래서 dp[3] = score[3] + max(score[1], score[2]);
 */