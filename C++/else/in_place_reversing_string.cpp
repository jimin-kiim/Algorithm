//
// Created by 김지민 on 2023/06/30.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int num = 0;
        int size = s.size();
        for (int i = size; i > 0; i--) {
            s.insert(s.begin() + num, 1, s[size - 1]);
            s.pop_back();
            num += 1;

            #if false
            for(vector<char>::iterator iter = s.begin(); iter != s.end(); iter++)
                cout << *iter;
            cout << "\n";
            #endif
        }
    }
};


int main() {
    Solution sol = Solution();
    string str = "hello!";
    vector<char> strToChar(str.begin(), str.end());
    sol.reverseString(strToChar);
}