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
        recurrence(nums, permutation, is_used, result);
        return result;
    }

    void recurrence(vector<int>& nums, vector<int> permutation, vector<int>& is_used, vector<vector<int>>& result) { // k means kth number in a permutation
        if (permutation.size() == nums.size()) {
            result.push_back(permutation);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if(!is_used[i]) {
                permutation.push_back(nums[i]);
                is_used[i] = 1;
                recurrence(nums, permutation, is_used, result);
                is_used[i] = 0;
                permutation.pop_back();
            }
        }
    }
};