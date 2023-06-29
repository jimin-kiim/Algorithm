//
// Created by 김지민 on 2023/06/29.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        for(int i = 0; i < ransomNote.size(); i++) {
            for(int j = 0; j < magazine.size(); j++) {
                if (ransomNote[i] == magazine[j]) {
                    magazine.replace(j, 1, "A");
                    break;
                } else if (j == magazine.size() - 1) {
                    return false;
                } else {
                    continue;
                }
            }
        }
        return true;
    }
};