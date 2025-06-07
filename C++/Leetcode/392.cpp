//
// Created by 김지민 on 6/7/25.
//
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.length() > t.length()) return false;
        int index = 0;
        for (int i = 0; i < s.length(); i++) {
            bool flag = false;
            for (int j = index; j < t.length(); j++) {
                if (s[i]==t[j]) {
                    flag = true;
                    index = j + 1;
                    if (i != s.length() -1 && j + 1 >= t.length()) return false;
                    break;
                }
                if (j == t.length() - 1) return false;
            }
            if (flag) continue;
        }
        return true;
    }
};