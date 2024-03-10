//
// Created by 김지민 on 3/10/24.
//
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> res;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    // n개 돌면서
    for (int i = 0; i < n; i++) res.push_back(i < m ? 0 : 1); // m개 까지는 0, 아니면 1 저장
    // -> 0 1로만 이루어진 오름차순 배열 저장 -> next_permutation 사용 가능

    do {
        // n개 돌면서
        for (int i = 0; i < n; i++) {
            if (res[i] == 0) cout << i + 1 << " "; // 0이면 해당 인덱스 값 + 1 만큼 출력
        }
        cout << "\n";
    } while (next_permutation(res.begin(), res.end()));
    // next_permutation: 오름차순으로 원소 중복 없는 순열 생성 (사용 가능 조건: 오름차순으로 정렬된 값을 가진 컨테이너 대상)
    // 두 개의 1이 위치할 자리를 가능한 여러 경우로 자동으로 바꿔주는 것이므로 원소의 중복 사용은 당연히 피하게 되고
    // 출력 시 0번 인덱스부터 차례로 돌기에 각 순열의 출력이 오름차순인 것도 유지된다.
}