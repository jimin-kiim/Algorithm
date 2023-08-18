//
// Created by 김지민 on 2023/08/18.
//
#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int> > v;
    int x, y;
    while (n--) {
        cin >> x >> y;
        v.push_back({x, y});
    }

    sort(v.begin(), v.end(), compare);

    for (pair<int, int> e: v) {
        cout << e.first << " " << e.second << "\n";
    }
}