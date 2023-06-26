//
// Created by 김지민 on 2023/06/26.
//
#include <iostream>
#include <string.h>
using namespace std;

int main_scanf_printf(void) {
    char a[10];
    printf("input : ");
    scanf("%s",a);
    printf("a is %s\n", a);
}
/**
* input: hi hello
 * output: a is hi
*/


int main_cin_cout(void) {
    string s;
    cout << "input : ";
    cin >> s;
    cout << "s is " << s;
}
/**
 * input: hi hello
 * output: a is hi
 */

/*
 * getting input line by line
 */
int main_modified(void) {
    char a1[10];
    scanf("%[^\n]", a1);

    char a2[10];
    gets(a2); // deprecated
    puts(a2);

    string s;
    getline(cin, s);
    cout << s;
}
