//
// Created by 김지민 on 2023/07/05.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string first;
        string second;
        cin >> first >> second;
        int flag = true;
        if (first.size() != second.size()) {
            cout << "Impossible" << "\n";
            continue;
        }
        if(first.size() >1000) {
            cout << "Impossible" << "\n";
            continue;
        }
        for (int j = 0; j < first.size(); j++) {
            int count = 0;
            for (; count < second.size(); count++) {
//                if (first[j] != second[count]) {
//                    count++;
//                } else {

//                    continue;
                if (first[j] == second[count]) {
                    second[count] = 'A';
                        break;
                }
            }
            if (count == second.size()) {
                cout << "Impossible" << "\n";
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "Possible" << "\n";
        }
    }
}