//
// Created by 김지민 on 2023/08/15.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int nums[n];
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums, nums + n);
    int N = nums[0] * nums[n - 1];
    cout << N;
}