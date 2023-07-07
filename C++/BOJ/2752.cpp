//
// Created by 김지민 on 2023/07/07.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[3];
    for (int i = 0; i < 3; i++) {
        cin >> arr[i];
    }
    int min = 1000000;
    int min_index = 0;
    int max = 0;
    int max_index = 0;
    for (int i = 0; i < 3; i++) {
        if(arr[i] < min) {
            min = arr[i];
            min_index = i;
        }
        if(arr[i] > max) {
            max = arr[i];
            max_index = i;
        }
    }
    int middle = 3 - min_index - max_index;
    cout << arr[min_index] << " " <<  arr[middle] << " " << arr[max_index];
}