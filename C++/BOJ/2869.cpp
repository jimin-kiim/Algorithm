//
// Created by 김지민 on 3/13/24.
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll a, b, v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> v;
    ll in_a_day = a - b;
    ll res = (v - b) / in_a_day;
    if ((v - b) % in_a_day != 0) res++;
    cout << res;
}