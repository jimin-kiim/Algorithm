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
    int height;
    stack<int> buildings;
    while (n--) {
        cin >> height;
        while (!buildings.empty() && buildings.top() <= height ) {
            buildings.pop();
        }
        count += buildings.size();
        buildings.push(height);
    }
    cout << count;
}

/*
 * 본인 이후에 들어오는 값들 중 본인보다 크거나 같은 값이 들어오기 전까지의 개수 카운팅.
 * -> 시간 초과
 *
 * 각각의 빌딩의 높이 값이 들어왔을 때마다 이를 볼 수 있는 빌딩의 개수를 센다.
 * 해당 빌딩보다 높지만 뒤에 들어오는 빌딩은 어차피 이를 볼 수 없기 때문에 신경을 쓰지 않아도 된다.
 * 이미 있는 빌딩 높이보다 높은 빌딩이 들어오는 순간 이미 있던 작은 빌딩은 더 이상 더 들어오는 빌딩들을
 * 볼 수 없기에 개수 세기에서 제외된다. 즉 pop
 * 즉 스택에 있는 빌딩들: 앞으로 들어올 빌딩들을 볼 수도 있는 빌딩들.
 * 개수 세기에서 제외될지 안 될지는 새로 들어온 높이 값에 따라.
 *
 * 로직은 분명 맞는 것 같은데 틀렸다고 할 경우 int, long long 다시 살펴보기
 * 높이가 내림차순이 되도록 80000 개 빌딩이 있으면 count 값 32억 정도.
 */