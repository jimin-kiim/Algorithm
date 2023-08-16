//
// Created by 김지민 on 2023/08/16.
//
#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;

    int total = 0;
    while (t--) {
        int opd1, opd2;
        string op;
        cin >> opd1 >> op >> opd2;
        if (op == "+") {
            total += opd1 + opd2;
        } else if (op == "-") {
            total += opd1 - opd2;
        } else if (op == "*") {
            total += opd1 * opd2;
        } else if (op == "/") {
            total += opd1 / opd2;
        }
    }

    cout << total;
    return 0;
}