//
// Created by 김지민 on 2023/08/23.
//
#include <bits/stdc++.h>
using namespace std;

int neg[10000001];
int pos[10000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n;

    int input;
    while (n--) {
        cin >> input;
        if (input < 0) {
            neg[-input] += 1;
        } else {
            pos[input] += 1;
        }
    }

    cin >> m;
    while (m--) {
        cin >> input;
        if (input < 0 ) {
            cout << neg[-input] << " ";
        } else {
            cout << pos[input] << " ";
        }
    }
}