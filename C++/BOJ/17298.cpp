//
// Created by 김지민 on 2023/08/01.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n];
    int ans[n];
    stack<int> s;

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && s.top() <= a[i]) {
            s.pop();
        }
        if (s.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = s.top();
        }
        s.push(a[i]);
    }
    for (int c: ans) cout << c << " ";
}

/*
 * 차례로 수를 받고 역순으로 비교.
 * 스택에 있는 수: 잠재적으로 앞으로 들어올 수들보다 클 것 같은 수들.
 * 들어온 수가 더 클 경우: 스택 top이 pop된다.
 *
 */