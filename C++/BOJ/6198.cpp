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
    long long height;
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
 * 각각의 높이가 들어왔을 때 이를 볼 수 있는 빌딩의 개수를 센다.
 * 해당 빌딩 보다 높지만 뒤에 들어오는 빌딩은 어차피 이를 볼 수 없기 때문에 신경을 쓰지 않아도 된다.
 *
 *
 */