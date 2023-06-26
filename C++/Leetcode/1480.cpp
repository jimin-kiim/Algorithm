//
// Created by 김지민 on 2023/06/26.
//

/**
 * input: nums
 * output: sum = [nums[0], sum[0]+nums[1], sum[1]+nums[2] ... ]
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> res;
        int size = nums.size();
        res.push_back(nums[0]);
        for(int i = 1; i < size; i++) {
            res.push_back(res[i-1]+nums[i]);
        }
        return res;
    }
};