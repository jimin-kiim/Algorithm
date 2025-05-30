//
// Created by 김지민 on 5/30/25.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > result;
        vector<int> combination;
        recurrence(1, result, combination, n, k);
        return result;
    }

    void recurrence(int start, vector<vector<int> >& result, vector<int>& combination, int n, int k) {
        if (combination.size() == k) {
            result.push_back(combination);
            return;
        }

        for (int i = start; i <= n; i++) {
            combination.push_back(i);
            recurrence(start + 1, result, combination, n, k);
        }
    }
};