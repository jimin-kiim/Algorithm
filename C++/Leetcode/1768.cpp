class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int size = min(word1.size(), word2.size());

        string result = "";
        for (int i = 0; i < size; i++) {
            result += word1[i];
            result += word2[i];
        }

        word1.erase(0, size);
        word2.erase(0, size);

        result += word1;
        result += word2;

        return result;
    }
};