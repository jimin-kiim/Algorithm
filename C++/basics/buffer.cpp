//
// Created by 김지민 on 2023/06/26.
//
#include <iostream>
using namespace std;

int main(void) {
    cin.tie(0); // make cin skip emptying the cout buffer in order to reduce the runtime
    for (int i = 0; i < 3; i++) {
        int a, b;
        cin >> a >> b; // in default, cin empties the cout buffer before it gets the input
        cout << a + b << '\n';
        // never use 'endl' in order to reduce the runtime
        // endl: print ₩n and empty the printing buffer
    }
}