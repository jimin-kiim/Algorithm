class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string result = "";
        int size = min(str1.size(), str2.size());

        for (int i = 0; i < size; i++) {
            if (str1[i] != str2[i]) break;
            result += str1[i];
        }

        return result;
    }
};