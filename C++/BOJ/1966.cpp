//
// Created by 김지민 on 2023/08/24.
//
#include <bits/stdc++.h>
using namespace std;

int print(deque<pair<int, bool> >& d, vector<int>& p) {
    int count = 0;
    while (1) {
        if (d.front().first != p.back()) {
            d.push_back(d.front());
            d.pop_front();
        } else {
            if (d.front().second == true) {
                cout << ++count << "\n";
                return 0;
            } else {
                d.pop_front();
                count++;
                p.pop_back();
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    int num, index;
    int input;
    while (n--) {
        cin >> num >> index;
        deque<pair<int, bool> > d;
        vector<int> p_list;
        for (int i = 0; i < num; i++) {
            cin >> input;
            if (i == index) {
                d.push_back({input, true});
            } else {
                d.push_back({input, false});
            }
            p_list.push_back(input);
        }
        sort(p_list.begin(), p_list.end());
        print(d, p_list);
    }
}