//
// Created by 김지민 on 2023/07/05.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, limit;
    int students[2][6] = {};
    cin >> k >> limit;
    for (int i = 0; i < k; i++) {
        int is_male, grade;
        cin >> is_male >> grade;
        students[is_male][grade - 1] += 1;
    }

    int count = 0;
    for(int i = 0; i < 2; i++) {
        for (int j = 0; j < 6; j++) {
            int student = students[i][j];
            count += student / limit;
            if(student%limit != 0) count++;
        }
    }
    cout << count;
}