//
// Created by 김지민 on 2023/08/18.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> v;
    int input;
    while (n--) {
        cin >> input;

        bool is_already = false;

        for (int e: v) {
            if (e == input) {
                is_already = true;
                break;
            }
        }

        if (!is_already) v.push_back(input);
    }

    sort(v.begin(), v.end());
    for (int e: v) cout << e << " ";
}