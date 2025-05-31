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
            recurrence(i + 1, result, combination, n, k);
            combination.pop_back();
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution solution;
    vector<vector<int> > result = solution.combine(4, 2);
    cout << "[";
    for (vector<int> combination: result) {
        cout << "[";
        for (int i = 0; i < combination.size(); i++) {
            cout << combination[i];
            if (i != combination.size() - 1) {
                cout << ",";
            }
        }
        cout << "]";
    }
    cout << "]";
}