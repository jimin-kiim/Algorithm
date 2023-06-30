//
// Created by 김지민 on 2023/06/30.
//

#include <bits/stdc++.h>
using namespace std;

void printReverse(const char *str) {
    if (!*str)
        return;
    printReverse(str + 1);
    putchar(*str);
}

int main() {
    char* str = "ABCdef";
    printReverse(str);
}