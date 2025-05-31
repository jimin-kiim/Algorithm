//
// Created by 김지민 on 5/31/25.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        /*
         *         vector<vector<char> > tablet = {{'a', 'b', 'c'},
                                        {'d', 'e', 'f'},
                                        {'g', 'h', 'i'},
                                        {'j', 'k', 'l'},
                                        {'m', 'n', 'o'},
                                        {'p', 'q', 'r', 's'},
                                        {'t', 'u', 'v'},
                                        {'w', 'x', 'y', 'z'}
        };
         */

        vector<string> tablet = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        vector<int> digits_int;
        for (char digit: digits_int) {
            digits_int.push_back(digit - '0');
        }

        vector<string> result;
        string sequence = "";

        combine(0, result, sequence, digits_int, tablet);
        return result;
    }

    void combine(int start, vector<string>& result, string sequence, vector<int>&digits_int, vector<string> tablet) {
        if (sequence.size() == digits_int.size()) {
            result.push_back(sequence);
            return;
        }

        /*
        sequence.push_back(tablet[digits_int[i]+2]);
        sequence.push_back(tablet[digits_init[j]+2]);
        sequence.push_back(tablet[digits_init[k]+2]);
        sequence.push_back(tablet[digits_init[l]+2]);
        */

        /*
        for (int i = start; i < digits_int.size(); i++) {
            sequence.push_back(tablet[digits_int[i] + 2]);
            combine(i + 1, result, sequence, digits_int, tablet);
            sequence.pop_back(tablet[digits_int[i] + 2])
        }
        */

        for (int i = start; i < digits_int.size(); i++) {
            for (int j = 0; j < [digits_int[i] + 2].size(); j++) {
                sequence.push_back(tablet[digits_int[i] + 2][j]);
                combine(i + 1, result, sequence, digits_int, tablet);
                sequence.pop_back(tablet[digits_int[i] + 2][j]);
            }
        }

    }
};