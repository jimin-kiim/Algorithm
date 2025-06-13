//
// Created by 김지민 on 5/30/25.
//
#include <bits/stdc++.h>
using namespace std;

void recurrence(int current_index, vector<int> subset, vector<int> palette, int s, int& result) {
    int sum = 0;
    for (int i = 0; i < subset.size(); i++) {
        sum += subset[i];
    }
//    if (sum >= s ) { // wrong termination condition. the trend of the sum can be \/ form. it prunes untimely.
//        if (sum == s && !subset.empty()) result++;
//        return;
//    }

    if (current_index == palette.size()) {
        if (sum == s && !subset.empty() ) result++;
        return;
    }

    // wrong approach; it's for getting a combination, not a subset.
    // combination is for selecting items as much as a determined size. totally different with getting subsets.
//    for (int i = current_index; i < palette.size(); i++) {
//        subset.push_back(palette[i]);
//
//        recurrence(i + 1, subset, palette, s, result);
//        subset.pop_back();
//    }

    subset.push_back(palette[current_index]);
    recurrence(current_index + 1, subset, palette, s, result);
    subset.pop_back();

    recurrence(current_index + 1, subset, palette, s, result);
}

int main() {
    int n, s;
    int result = 0;
    vector<int> palette;
    cin >> n >> s;

    sort(palette.begin(), palette.end());
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        palette.push_back(input);
    }

    vector<int> subset;
    recurrence(0, subset, palette, s, result);
    cout << result;
}

