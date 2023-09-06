//
// Created by 김지민 on 2023/09/05.
//
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<vector<string> > tot_case;
    vector<string> tot_substr;
    for (int i = 1; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            vector<string> partitioned;
            partitioned.push_back(s.substr(0, i));
            tot_substr.push_back(s.substr(0, i));
            partitioned.push_back(s.substr(i, j - i));
            tot_substr.push_back(s.substr(i, j - i));
            partitioned.push_back(s.substr(j, n - j));
            tot_substr.push_back(s.substr(j, n - j));
            tot_case.push_back(partitioned);
        }
    }
    sort(tot_substr.begin(), tot_substr.end());
    tot_substr.erase(unique(tot_substr.begin(), tot_substr.end()), tot_substr.end());

    int ans = 0;
    for (vector<string> c: tot_case) {
        int score = 0;
        for (string s: c) {
            score += find(tot_substr.begin(), tot_substr.end(), s) - tot_substr.begin() + 1;
        }
        ans = max(ans, score);
    }
    cout << ans;
    return 0;
}