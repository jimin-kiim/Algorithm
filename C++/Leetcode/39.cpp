//
// Created by 김지민 on 6/5/25.
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > result;
        vector<int> combination;

        recurrence(0, result, combination, candidates, target);

        return result;
    }

    void recurrence(int start, vector<vector<int> >& result, vector<int> combination, vector<int>& candidates, int& target) {
        int sum = 0;
        for (int element: combination) {
            sum += element;
        }

        // termination condition
        if (sum >= target) {
            if (sum == target) {
                result.push_back(combination);
            }
            return;
        }

        // building up a combination
        for (int i = start; i < candidates.size(); i++) {
            // building up
            combination.push_back(candidates[i]); //
            // proceed
            recurrence(i, result, combination, candidates, target);
            // backtracking
            combination.pop_back();
        }
    }
};

int main() {
    // 중복 허용 combination을 만들다가 합을 구해서 target이 되면 output에 저장 후 리턴.
    // combination -> backtracking.
    // backtracking: termination condition, promising function, recurrence, backtracking.
    // 중복 허용 -> is_used 어레이를 사용하지 않는다.
    // termination condition: 합이 target >= 일 때
    // 순열이 아닌 조합이기에 for (int i = start; i < candidates.size(); i++) 사용
    // 전체 경우의 수가 150개 이하라고 하기에 타임 아웃은 되지 않을 것이다.

    Solution solution;
    vector<int> candidates = {2, 3, 5};
    int target = 8;
    solution.combinationSum(candidates, target);

}