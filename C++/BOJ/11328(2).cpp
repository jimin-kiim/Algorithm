//
// Created by 김지민 on 2023/07/09.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int arr[26] = {};
        string first;
        string second;
        cin >> first >> second;
        for (char c : first) {
            arr[c -'a']++;
        }
        for (char c : second) {
            arr[c - 'a']--;
        }
        int flag = true;
        for (int j = 0; j < 26; j++) {
            if (arr[j] != 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "Possible\n";
        } else {
            cout << "Impossible\n";
        }
    }
}