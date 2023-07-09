//
// Created by 김지민 on 2023/07/09.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    string first, second;
    cin >> first >> second;
    int arr[26] = {};
    for (char c: first) {
        arr[c- 'a']++;
    }
    for (char c: second) {
        arr[c - 'a']--;
    }
    int count = 0;
    for (int e: arr) {
        if (e != 0) count += abs(e);
    }
    cout << count;
}