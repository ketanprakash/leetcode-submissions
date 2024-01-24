class Solution {
public:
    int firstUniqChar(string &str) {
        int freq[26] = {0};

        for (auto &ch : str) freq[ch - 'a']++;

        for (int i = 0; i < str.size(); i++){
            if (freq[str[i] - 'a'] == 1) return i;
        }

        return -1;
    }
};