class Solution {
public:
    int longestPalindrome(string &str) {
        int freq[128] = {0};

        for (int i = 0; i < str.size(); i++){
            freq[str[i]]++;
        }

        bool flag = false;

        for (int i = 0; i < 128; i++){
            if (freq[i] % 2 != 0) flag = true;
            freq[i] /= 2;
        }

        return 2 * accumulate(freq, freq + 128, 0) + flag;
    }
};