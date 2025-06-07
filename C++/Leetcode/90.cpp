//
// Created by 김지민 on 6/7/25.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;

        for (int length = 0; length <= nums.size(); length++) {
            recurrence(0, nums, result, subset, length);
        }
        return result;
    }

    void recurrence(int start, vector<int> nums, vector<vector<int>>& result, vector<int> subset, int length) {
        if (subset.size() == length) {
            result.push_back(subset);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            subset.push_back(nums[i]);
            recurrence(i + 1, nums, result, subset, length);
            subset.pop_back();
        }
    }
};

int main() {
    Solution solution;

    vector<int> nums = {1, 2, 2};
    vector<vector<int>> result = solution.subsetsWithDup(nums);
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << "[";
        for (int j = 0 ; j < result[i].size(); j++) {
            cout << result[i][j];
            if (j != result[i].size() - 1) {
                cout << ",";
            }
        }
        cout << "]";
    }
    cout << "]";
}