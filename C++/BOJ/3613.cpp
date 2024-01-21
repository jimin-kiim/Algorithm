//
// Created by 김지민 on 1/21/24.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string input;
    cin >> input;

    string result = "";

    bool should_be_capital = false;
    for (int i = 0; i < input.size(); i++) {
        char value = input[i];

        if (should_be_capital == false && islower(input[i]) == true) {
            result += value;
            continue;
        }
        if (input[i] == '_') {
            should_be_capital = true;
            continue;
        }

        if (should_be_capital == true) {
            result += toupper(value);
            should_be_capital = false;
            continue;
        }

        result += "_";
        result += tolower(value);
    }

    cout << result;
}

/*
 * _가 등장하면 삭제 후 다음 문자 대문자로
 *
 * 대문자가 등장하면 _추가 후 다음 문자 소문자로
 */