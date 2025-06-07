//
// Created by 김지민 on 6/5/25.
//
#include <bits/stdc++.h>
using namespace std;

// 백준 N과 M 문제 시리즈는 부분 집합/수열의 크기가 고정되어 있고 그 기준에 맞는 부분 집합/수열을 구하는 거라면, 이번 문제는 그 크기가 0부터 palette 길이만큼까지.
// => N과 M 문제 푸는 방식에 for 문을 입혀서 구현한다.

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        for (int length = 0; length <= nums.size(); length++) {
            vector<int> subsequence;
            recurrence(0, result, nums, subsequence, length);
        }
        return result;
    }

    void recurrence(int start, vector<vector<int>>& result, vector<int> nums, vector<int> subsequence, int length) {
        // termination condition
        if (subsequence.size() == length) {
            result.push_back(subsequence);
        }

        // building a sequence
        for (int i = start; i < nums.size(); i++) {
            // since it's building combination and the duplicate usage of the elements is not allowed
            // but proceeding with the next element from the sequence meets the constraint, there's no promising function needed.
            // if it's getting permutations, is_used might be needed.
            subsequence.push_back(nums[i]);
            // recurrence
            recurrence(i + 1, result, nums, subsequence, length);
            // backtracking
            subsequence.pop_back();
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = solution.subsets(nums);

    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if (j != result[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i != result.size() - 1) cout << ",";
    }
    cout << "]";
}