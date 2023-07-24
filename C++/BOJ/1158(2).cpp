//
// Created by 김지민 on 2023/07/24.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> people;
    for (int i = 1; i < n + 1; i++) people.push_back(i);

    vector<int> output;
    for (int i = 0; output.size() < n; i++) {
        if (i % k == k - 1) output.push_back(people[i]);
        else people.push_back(people[i]);
    }

    cout << "<";
    for (int i = 0; i < n; i++) {
        if (i == n - 1) cout << output[i] << ">";
        else cout << output[i] << ", ";
    }
}