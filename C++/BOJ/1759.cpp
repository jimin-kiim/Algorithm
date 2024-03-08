//
// Created by 김지민 on 3/8/24.
//
#include <bits/stdc++.h>
using namespace std;

int l, c;
int res_indices[15];
char palette[15];

void func(int k) {
    if (k == l) {
        int flag = 0;
        for (int i = 0; i < l; i++) {
            char value = palette[res_indices[i]];
            if (value == 'a' || value == 'e' || value == 'i' || value == 'o' || value == 'u') {
                flag = 1;
                break;
            }
        }
        if (flag != 1) return;
        for (int i = 0; i < l; i++) {
            cout << palette[res_indices[i]];
        }
        cout << "\n";
        return;
    }

    int start = 0;
    if (k != 0) start = res_indices[k - 1] + 1;
    for (int i = start; i < c; i++) {
        res_indices[k] = i;
        func(k + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> l >> c;
    for (int i = 0; i < c; i++) {
        cin >> palette[i];
    }

    sort(palette, palette + c);
    func(0);
}