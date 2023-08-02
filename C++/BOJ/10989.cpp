//
// Created by 김지민 on 2023/08/02.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, input;
    cin >> n;

    vector<int> nums;
    for (int i = 0; i < n; i++) {
        cin >> input;
        nums.push_back(input);
    }
    sort(nums.begin(), nums.end());
    for (int e: nums) cout << e << "\n";
}