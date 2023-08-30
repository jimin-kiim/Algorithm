//
// Created by 김지민 on 2023/08/15.
//
#include <bits/stdc++.h>
using namespace std;

int k;
int result[6];
bool is_used[50];
int palette[14];

void func(int n) {
    if (n == 6) {
        for (int i = 0; i < 6; i++) cout << result[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = 0; i < k; i++) {
        if(!is_used[palette[i]]) {
            result[n] = palette[i];
            is_used[palette[i]] = 1;
            func(n + 1);
            is_used[palette[i]] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1) {
        cin >> k;
        if (k == 0) break;

        for (int i = 0; i < k; i++) cin >> palette[i];
        func(0);
        cout << "\n";
    }

}