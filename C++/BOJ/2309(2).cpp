 //
// Created by 김지민 on 2023/07/12.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int nums[9];
    int sum = 0;
    for (int i = 0; i < 9; i++) {
        int input;
        cin >> input;
        sum += input;
        nums[i] = input;
    }

    int target = sum - 100;
    int flag = false;
    for (int i = 0; i < 9; i++) {
        for (int j = i; j < 9; j++) {
            if (nums[i] + nums [j] == target && i != j) {
                nums[i] = nums[j] = 0;
                flag = true;
                break;
            }
        }
        if (flag) break;
    }
    sort(nums, nums + 9);
    for (int i = 2; i < 9; i++)
        cout << nums[i] << "\n";
}