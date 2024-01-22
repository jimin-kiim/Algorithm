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

    // 시작이 대문자일 때
    if (isupper(input[0])) {
        cout << "Error!";
        return 0;
    }

    // 맨 처음이 _로 시작할 때
    if (input[0] == '_') {
        cout << "Error!";
        return 0;
    }

    // 마지막이 _로 끝날 때
    if (input[input.size() - 1] == '_') {
        cout << "Error!";
        return 0;
    }

    // _가 연속으로 있을 때
    if (input.find("__") != string::npos) {
        cout << "Error!";
        return 0;
    }

    string result;

    bool should_be_capital = false;
    bool is_java = false;
    bool is_cpp = false;

    for (int i = 0; i < input.size(); i++) {
        char value = input[i];

        // java인데 _등장
        if (is_java && value == '_') {
            cout << "Error!";
            return 0;
        }

        // cpp인데 대문자 등장
        if (is_cpp && isupper(value)) {
            cout << "Error!";
            return 0;
        }

        // _도 아니고 알파벳도 아닌 문자가 포함됐을 때
        if (value != '_' && isalpha(value) == false) {
            cout << "Error!";
            return 0;
        }



        // 대문자가 되어야하는 조건이 아닌 소문자는 그대로 저장
        if (!should_be_capital && islower(value)) {
            result += value;
            continue;
        }

        if (value == '_') {
            should_be_capital = true;
            is_cpp = true;
            continue;
        }

        // _다음 문자는 대문자로 변환해서 저장
        if (should_be_capital) {
            result += toupper(value);
            should_be_capital = false;
            continue;
        }

        // _ 등장한 적 없고 대문자 나왔을 때
        if (isupper(value)) {
            is_java = true;
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