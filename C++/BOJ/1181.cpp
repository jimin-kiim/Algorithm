//
// Created by 김지민 on 2023/08/18.
//
#include <bits/stdc++.h>
using namespace std;

bool compare(string& x, string& y) {
    if (x.size() == y.size()) return x < y;
    return x.size() < y.size();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<string> v;
    string input;
    for (int i = 0; i < n; i++){
        cin >> input;
        v.push_back(input);
    }
    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < n; i++) {
        if (v[i] == v[i + 1]) continue;
        cout << v[i] << "\n";
    }
}