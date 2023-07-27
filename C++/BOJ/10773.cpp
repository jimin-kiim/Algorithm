//
// Created by 김지민 on 2023/07/27.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int k;
    cin >> k;

    stack<int> s;
    while(k--) {
        int data;
        cin >> data;
        if (!s.empty() && data == 0) s.pop();
        else s.push(data);
    }

    int sum = 0;
    while (!s.empty()) {
        sum += s.top();
        s.pop();
    }
    cout << sum;
}