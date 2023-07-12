//
// Created by 김지민 on 2023/07/12.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[21] ={};
    for (int i = 1; i < 21; i++) {
        arr[i] = i;
    }
    for (int i = 0; i < 10; i++) {
        int a, b;
        cin >> a >> b;
        vector<int> temp;
        for (int j = a; j < b + 1; j++) {
            temp.push_back(arr[j]);
        }
        for (int j = a; j < b + 1; j++) {
            arr[j] = temp[temp.size() - 1];
            temp.pop_back();
        }
    }
    for (int i = 1; i < 21; i++) {
        cout << arr[i] << " ";
    }
}