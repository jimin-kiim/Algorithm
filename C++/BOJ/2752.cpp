//
// Created by 김지민 on 2023/07/07.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    int min_value, max_value;
    cin >> a >> b >> c;
    min_value = min({a, b, c});
    max_value = max({a, b, c});
    int middle = a + b + c - min_value - max_value;
    cout << min_value << " " <<  middle << " " << max_value;
}