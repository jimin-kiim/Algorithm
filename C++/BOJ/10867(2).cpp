//
// Created by 김지민 on 2023/08/23.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios:: sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> nums;
    int input;
    while (n--) {
        cin >> input;
        nums.push_back(input);
    }

    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    for (int e: nums) cout << e << " ";
}