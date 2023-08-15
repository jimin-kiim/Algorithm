//
// Created by 김지민 on 2023/08/15.
//
#include <iostream>
using namespace std;
int main() {
    int w;
    float r;
    cin >> w;
    cin >> r;

    int rm = w * (1 + r / 30);
    cout << rm;
    return 0;
}