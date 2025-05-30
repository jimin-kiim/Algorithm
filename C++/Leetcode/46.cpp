//
// Created by 김지민 on 5/30/25.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > result;
        vector<int> permutation;
        vector<int> is_used(nums.size(), 0);
        recurrence(0, nums, permutation, is_used, result);
        return result;
    }

    void recurrence(int k, vector<int>& nums, vector<int> permutation, vector<int>& is_used, vector<vector<int>>& result) { // k means kth number in a permutation
        if (k == nums.size()) {
            result.push_back(permutation);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if(!is_used[nums[i]]) {
                permutation.push_back(nums[i]);
                is_used[nums[i]] = 1;
                recurrence(k + 1, nums, permutation, is_used, result);
                is_used[nums[i]] = 0;
                permutation.pop_back();
            }
        }
    }
};