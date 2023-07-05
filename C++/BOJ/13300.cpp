//
// Created by 김지민 on 2023/07/05.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, limit;
    int female_students[6] = {};
    int male_students[6] = {};
    cin >> k >> limit;
    for (int i = 0; i < k; i++) {
        int is_male, grade;
        cin >> is_male >> grade;
        if (is_male) {
            male_students[grade - 1] += 1;
        } else {
            female_students[grade - 1] += 1;
        }
    }
    int count = 0;
    for (int e: female_students)  {
        count += e / limit;
        if(e%limit != 0) count++;
    }
    for (int e: male_students)  {
        count += e / limit;
        if(e%limit != 0) count++;
    }
    cout << count;
}