//
// Created by 김지민 on 2023/08/07.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios:: sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int ppl[n];
    for (int i = 0; i < n; i++) cin >> ppl[i];
    stack<int> s;
    long long count = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (!s.empty() && s.top() == ppl[i]) count++;
        while (!s.empty() && s.top() < ppl[i]) {
                s.pop();
                count++;
        }
        s.push(ppl[i]);
    }

    stack<int> s2;
    for (int i = 0; i < n; i++) {
        while (!s2.empty() && s2.top() < ppl[i]) {
            s2.pop();
            count++;
        }
        s2.push(ppl[i]);
    }

    cout << count;
}

/*
 * 2 4 1 2 2 5 1
 */