//
// Created by 김지민 on 1/22/24.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> v;

    while (n--) {
        string input;
        cin >> input;

        bool is_prev_digit = false;
        string number;

        for (int i = 0; i < input.size(); i++) {
            if (!is_prev_digit && isalpha(input[i])) continue;
            if (isalpha(input[i])) {
                v.push_back(stoi(number));
                number = "";
                is_prev_digit = false;
                continue;
            }
            number += input[i];
            is_prev_digit = true;

            if (i == input.size() - 1) {
                v.push_back(stoi(number));
            }
        }
    }

    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        cout << v.at(i);
        if (i != v.size() - 1) cout << "\n";
    }
}