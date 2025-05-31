//
// Created by 김지민 on 5/31/25.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> tablet = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; // multiple palettes

        vector<int> digits_int;
        for (char digit: digits) {
            digits_int.push_back(digit - '0');
        }

        vector<string> result = {};
        string sequence = "";

        // start calling the recurrence function
        combine(0, result, sequence, digits_int, tablet);
        return result;
    }

    void combine(int key, vector<string>& result, string sequence, vector<int>&digits_int, vector<string> tablet) {
        // termination condition
        if (digits_int.size() == 0) {
            return;
        }

        if (sequence.size() == digits_int.size()) {
            result.push_back(sequence);
            return;
        }

        // building a combination
        for (int j = 0; j < tablet[digits_int[key] - 2].size(); j++) {
            sequence.push_back(tablet[digits_int[key] - 2][j]);
            // recurrence
            combine(key + 1, result, sequence, digits_int, tablet);
            // backtracking
            sequence.pop_back();
        }
    }
};

int main() {
    Solution solution;
    solution.letterCombinations("");
}