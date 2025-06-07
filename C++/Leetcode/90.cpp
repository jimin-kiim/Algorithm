//
// Created by 김지민 on 6/7/25.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end()); // not to make [4,1], [1,4]. [1,4] [4,1] is allowed.
        vector<vector<int>> result;
        vector<int> subset;
        set<vector<int>> seen;

        // 공집합부터 원본 크기만큼
        for (int length = 0; length <= nums.size(); length++) {
            recurrence(0, nums, result, subset, length, seen);
        }
        return result;
    }

    void recurrence(int start, vector<int> nums, vector<vector<int>>& result, vector<int> subset, int length, set<vector<int>>& seen) {
        if (subset.size() == length) {
            if (seen.count(subset)) return;
            seen.insert(subset);
            result.push_back(subset);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            subset.push_back(nums[i]);
            recurrence(i + 1, nums, result, subset, length, seen);
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

/*
 * Mistakes
 * set<int> key (subset.begin(), subset.end()); : [1,2], [1,1,2], [1,2,2], [1,2,2,2] 등을 모두 같은 값 {1,2}으로 인식.
 *
 *
 */