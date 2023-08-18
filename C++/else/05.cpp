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
        const int input;
        int count = 0;
        cin >> input;
        string binary = bitset<input>(decimal).to_string();
        for (char c: binary) {
            if (c == "1") count++;
        }
        v.push_back(input, count);
    }

    sort(v.begin(), v.end(), second);
    cout << v[k];
}