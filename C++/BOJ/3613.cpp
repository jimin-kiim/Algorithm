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
    bool did_capital_appear = false;
    bool did_underscore_appear = false;

    for (int i = 0; i < input.size(); i++) {
        char value = input[i];

        // 시작이 대문자일 때
        if (i == 0 && isupper(value)) {
            cout << "Error!";
            return 0;
        }

        // 맨 처음이 _로 시작할 때
        if (i == 0 && value == '_') {
            cout << "Error!";
            return 0;
        }

        // 마지막이 _로 끝날 때
        if (value == '_' && i == input.size() - 1) {
            cout << "Error!";
            return 0;
        }

        // 맨 처음에 소문자로 시작할 땐 소문자 그대로 저장
        if (!should_be_capital && islower(value) == true) {
            result += value;
            continue;
        }

        // 처음 _가 등장했을 때

        if (did_capital_appear && value == '_') {
            cout << "Error!";
            return 0;
        }

        if (!should_be_capital && value == '_') {
            should_be_capital = true;
            did_underscore_appear = true;
            continue;
        }

        // _가 연속해서 등장했을 때
        if (should_be_capital && value == '_') {
            cout << "Error!";
            return 0;
        }

        // _도 아니고 알파벳도 아닌 문자가 포함됐을 때
        if (value != '_' && isalpha(value) == false) {
            cout << "Error!";
            return 0;
        }

        // _ 등장한 적이 있는데 대문자 나왔을 때
        if (did_underscore_appear && isupper(value)) {
            cout << "Error!";
            return 0;
        }

        // _다음 문자는 대문자로 변환해서 저장
        if (should_be_capital) {
            result += toupper(value);
            should_be_capital = false;
            continue;
        }

        // _ 등장한 적 없고 대문자 나왔을 때
        if (isupper(value)) {
            did_capital_appear = true;
            result += "_";
            result += tolower(value);
        }
    }

    cout << result;
}

/*
 * _가 등장하면 삭제 후 다음 문자 대문자로
 *
 * 대문자가 등장하면 _추가 후 다음 문자 소문자로
 *
 * 형식에 어긋나면 에러
 */