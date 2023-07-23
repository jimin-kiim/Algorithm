//
// Created by 김지민 on 2023/07/24.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    while(n--) {
        string input;
        cin >> input;

        list<char> buffer = {};
        list<char>:: iterator t = buffer.begin();

        for (int i = 0; i < input.size(); i++) {
            if (t != buffer.begin() && input[i] == '<') t--;
            else if (t != buffer.end() && input[i] == '>') t++;
            else if (t != buffer.begin() && input[i] == '-') {
                t--;
               t = buffer.erase(t);
            }
            else if (input[i] != '>' && input[i] != '<' && input[i] != '-') {
                buffer.insert(t, input[i]);
            }
        }
        for (list<char>::iterator it = buffer.begin(); it != buffer.end(); it++) {
            cout << *it;
        }
        cout << "\n";
    }
}