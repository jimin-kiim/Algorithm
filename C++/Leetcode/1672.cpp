//
// Created by 김지민 on 2023/06/28.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int> >& accounts) {
        int max = 0;
        int row_num = accounts.size();
        int col_num = accounts[0].size();
        for(int i = 0; i < row_num; i++) {
            int sum = 0;
            for(int j = 0; j < col_num; j++) {
                sum += accounts[i][j];
            }
            if (sum > max) {
                max = sum;
            }
        }
        return max;
    }
};
