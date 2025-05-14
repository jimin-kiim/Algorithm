//
// Created by 김지민 on 5/14/25.
//

class Solution {
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        string initial = s;
        int size = s.length();
        string updated_string;
        char alphabet[26];

        for (char c = 'a'; c <= 'z'; i++) {
            alphabet[i] = c;
        }

        while (t--) {
            for (int i = 0; i < size; i++) {
                string in_progress;
                int calculation = nums[updated_string[i] - 'a'];
                for (int j = 0; j < calculation; j++) {
                    in_progress += alphabet[s[i] - calculation + 1];
                }
            }
            updated_string = in_progress;
            size = updated_string.length();
        }

        return result.length() / (10^9  + 7);
    }
};

/*
 * input: s, t, nums
 *      s: string, consists of lower cases
 *      t: integer, the number of the transformation
 *      nums: array, whose size is 26.
 * output: the size of the result string, after all the transformation is applied to the string s.
 *
 * transformation: replace all the characters in s with a new string.
 *                 replace s[i] with the size of nums[s[i] - 'a'] characters, and they are consecutive characters in the alphabet.
 *
 *
 */