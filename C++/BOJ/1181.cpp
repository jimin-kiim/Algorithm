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

    vector<pair<int, string> > v;
    string input;
    while (n--) {
        cin >> input;
        int length = input.size();
        v.push_back({length, input});
    }

    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        cout << v[i].second << "\n";
    }
}