//
// Created by 김지민 on 3/13/24.
//
#include <bits/stdc++.h>
using namespace std;

long long a, b, v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> v;
    long long day = a - b;
    if (v % day == 0) cout << v / day;
    else cout << v / day + 1;
}