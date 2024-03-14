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
    ll day = a - b;
    ll res = (v - a) / day;
    if ((v - a) <= day) res++;
    cout << res + 1;
}