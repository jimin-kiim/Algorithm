//
// Created by 김지민 on 1/22/24.
//
#include <bits/stdc++.h>
using namespace std;

string erase_zeros(string input) {
    while(input.size() > 1) {
        if (input.front() == '0') {
            input.erase(0, 1);
        } else {
            return input;
        }
    }
    return input;
}

bool cmp(string a,string b) {
    if (a.length() == b.length()) return a < b;
    return a.length() < b.length();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<string> v;

    while (n--) {
        string input;
        cin >> input;

        bool is_prev_digit = false;
        string number;

        for (int i = 0; i < input.size(); i++) {
            if (!is_prev_digit && isalpha(input[i])) continue;
            if (isalpha(input[i])) {
                number = erase_zeros(number);
                v.push_back(number);
                number = "";
                is_prev_digit = false;
                continue;
            }
            number += input[i];
            is_prev_digit = true;

            if (i == input.size() - 1) {
                number = erase_zeros(number);
                v.push_back(number);
            }
        }
    }

    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++) {
        cout << v.at(i);
        if (i != v.size() - 1) cout << "\n";
    }
}