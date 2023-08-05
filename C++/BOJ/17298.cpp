//
// Created by 김지민 on 2023/08/01.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, input;
    cin >> n;

//    vector<int> ans;
    int ans[n];
    stack<pair<int, int>> s;

    for (int i = 0; i < n; i++) {
        cin >> input;
        int index = i;
        while (!s.empty() && s.top().first < input) {
            s.pop();
            ans[--index] = input;
        }
        s.push({input, i});
    }
    while (!s.empty()) {
        int diff = s.top().second;
            ans[diff] = -1;
        s.pop();
    }
    for (int c: ans) cout << c << " ";
}

/*
 * 스택에 있는 수: 잠재적으로 앞으로 들어올 수들보다 작을 것 같은 수들.
 * 실제로 작을 경우: pop된다. pop하는 횟수만큼 input 출력
 *
 */