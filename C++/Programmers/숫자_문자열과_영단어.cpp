//
// Created by 김지민 on 2023/09/26.
//
#include <bits/stdc++.h>
using namespace std;

int solution(string s) {
    vector<string> palette = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    for (int i = 0; i < palette.size(); i++) {
        size_t found = s.find(palette[i]);
        if (found!=std::string::npos) {
            s.replace(found, palette[i].size(), to_string(i));
        }
    }
    int answer = stoi(s);
    return answer;
}