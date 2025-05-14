//
// Created by 김지민 on 5/14/25.
//

class Solution {
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        string initial = s;
        int initial_size = s.length();
        string result;

        for (int i = 0; i < initial_size; i++) {
            int calculation = nums[s[i] - 'a'];
            for (int j = 0; j < calculation; j++) {
                result.apppend(s[i] - calculation + 1);
            }
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
 * transformation: replace s[i] with the size of nums[s[i] - 'a'] characters, and they are consecutive characters in the alphabet.
 *
 *
 */