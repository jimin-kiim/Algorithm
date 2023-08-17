//
// Created by 김지민 on 2023/08/17.
//
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int level;
    int max = 0;
    stack<int> s;
    int total = 0;
    for (int i = 0; i < n; i++) {
        cin >> level;
        s.push(level);
        if(level > max) max = level;
        total += level;
    }

    int prev = s.top();
    s.pop();
    while (1) {
        if (!s.empty() && s.top() > prev) {
            prev = s.top();
            s.pop();
        }
        else break;
    }

    if (s.top() != max) {
        cout << 0;
        return 0;
    }

    while (1) {
        if (!s.empty() && s.top() <= prev) {
            prev = s.top();
            s.pop();
        }
        else break;
    }

    if (s.empty()) cout << total;
    else cout << 0;

    return 0;
}
