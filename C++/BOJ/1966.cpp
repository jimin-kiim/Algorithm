//
// Created by 김지민 on 2023/08/24.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int num, index;
    int input;
    while (n--) {
        cin >> num >> index;
        vector<int> nums;
        while (num--) {
            cin >> input;
            nums.push_back(input);
        }
        int target = nums[index];
        sort(nums.begin(), nums.end(), greater<int>());
        auto it = find(nums.begin(), nums.end(), target);
        cout << it - nums.begin() + 1 << "\n";
    }
}