//
// Created by 김지민 on 2/15/24.
//
#include <bits/stdc++.h>
using namespace std;

int res[9]; // 정답 수열 기록
int is_used[9]; // 선택 가능한 수 팔레트
int n, m;

void func(int start, int k) { // k: 현재까지 택한 수의 개수
    // termination condition
    if (k == m) { // 종료 조건: m 개를 모두 택한 경우
        for (int i = 0; i < m; i++) // res에 기록해 둔 수 차례로 출력
            cout << res[i] << ' ';
        cout << '\n';
        return;
    }

    // selecting subsequent elements
    for (int i = start; i <= n; i++) {
        // promising function - not allowing the duplicate usage of an element
        if(!is_used[i]) {
            // building a solution - storing as a sequence constitution and marking as used.
            res[k] = i; // 아직 쓰인 적 없으면 k번째 수를 i로
            is_used[i] = 1; // i 사용했다고 표시
            // recurrence - keep going creating a sequence
            func(i + 1, k + 1); // k + 1번째 다음 수 정하러 한 단계 더 들어감. 순회 시작은 현재 값 + 1부터 (수열 구성 시 사용 후보 숫자는 중복 불가이자 오름차순 정렬로 구성)
            // backtracking - marking as unused.
            is_used[i] = 0; // k번째 수를 i로 정한 모든 경우에 대해 다 확인했으니 i를 이제 사용하지 않았다고 표시
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    func(1, 0);
}