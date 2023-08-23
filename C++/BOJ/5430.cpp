//
// Created by 김지민 on 2023/08/24.
//
#include <bits/stdc++.h>
using namespace std;

int print(string& p, deque<int>& v) {
    bool r_flag = false;
    for (char e: p) {
        if (e == 'D') {
            if (r_flag) {
                if (!v.empty()) {
                    v.pop_back();
                } else {
                    cout << "error\n";
                    return 0;
                }
            } else {
                if (!v.empty()) {
                    v.pop_front();
                } else {
                    cout << "error\n";
                    return 0;
                }
            }
        } else if (e == 'R') {
            if (r_flag) {
                r_flag = false;
            } else {
                r_flag = true;
            }
        }
    }

    cout << "[";
    while (v.size() > 1) {
        if (r_flag) {
            cout << v.back() << ",";
            v.pop_back();
        } else {
            cout << v.front() << ",";
            v.pop_front();
        }
    }
    if (!v.empty()) {
        cout << v.back();
    }
    cout << "]\n";
    return 0;
}

int main() {
    ios:: sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    string p, input;
    int n;
    while (t--) {
        cin >> p >> n >> input;
        string tmp = "";
        deque<int> v;
        for (int i = 1; i < input.size(); i++) {
            if (input[i] == ',' || input[i] == ']') {
                if (tmp != "") {
                    v.push_back(stoi(tmp));
                    tmp = "";
                }
            } else {
                tmp += input[i];
            }
        }
        print(p, v);
    }
}