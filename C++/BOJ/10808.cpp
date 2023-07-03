//
// Created by 김지민 on 2023/07/03.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[26];
    fill(arr, arr + 26, 0);

    string s;
    cin >> s;
    for (char c:s) {
        arr[c-'a'] += 1;
    }

    for (int e:arr) {
        cout << e << ' ';
    }
}