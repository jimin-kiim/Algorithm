//
// Created by 김지민 on 2023/06/26.
//

#include <vector>
using namespace std;

// TC: O(N)
// copying the whole vector values + comparing
bool cmp1(vector<int> v1, vector<int> v2, int idx) {
    return v1[idx] > v2[idx];
}

// O(1)
// comparing
bool cmp2(vector<int>& v1, vector<int>& v2, int idx) {
    return v1[idx] > v2[idx];
}