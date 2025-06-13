//
// Created by 김지민 on 6/13/25.
//
#include <bits/stdc++.h>
using namespace std;

void recurrence(int start, int length, vector<int> palette, vector<int> subset, int s, int& result) {
    if (subset.size() == length) {
        int sum = 0;
        for (int i = 0; i < subset.size(); i++) {
            sum += subset[i];
        }
        if (sum == s) result++;
        return;
    }

    for (int i = start; i < palette.size(); i++) {
        subset.push_back(palette[i]);
        recurrence(i + 1, length, palette, subset, s, result);
        subset.pop_back();
    }
}

int main() {
    int n, s;
    vector<int> array;

    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        array.push_back(input);
    }

    int result = 0;
    // nC1 + nC2 + ... + nCn approach
    for (int length = 1; length <= array.size(); length++) {
        vector<int> subset;
        recurrence(0, length, array, subset, s, result);
    }
    cout << result;
}