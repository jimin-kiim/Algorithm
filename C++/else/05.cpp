//
// Created by 김지민 on 2023/08/18.
//
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<pair<int, int> > v;

    while (n--) {
        int input;
        int count = 0;
        cin >> input;
        const int decimal = input;

        string binary = bitset<8>(decimal).to_string();
        for (char c: binary) {
            if (c == '1') count++;
        }
        v.push_back({count, input});
    }

    sort(v.begin(), v.end());
    cout << v[k];
}