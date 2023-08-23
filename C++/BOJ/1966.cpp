//
// Created by 김지민 on 2023/08/24.
//
#include <bits/stdc++.h>
using namespace std;

bool isTarget(pair<int, bool>& a) {
    return a.second == true;
}

int main() {
    int n;
    cin >> n;

    int num, index;
    int input;
    while (n--) {
        cin >> num >> index;
        vector<pair<int, bool> > nums;
        for (int i = 0; i < num; i++) {
            cin >> input;
            if (i == index) {
                nums.push_back({input, true});
            } else {
                nums.push_back({input, false});
            }
        }
        sort(nums.rbegin(), nums.rend());
        auto it = find_if(nums.begin(), nums.end(), isTarget);
        cout << it - nums.begin() + 1 << "\n";
    }
}