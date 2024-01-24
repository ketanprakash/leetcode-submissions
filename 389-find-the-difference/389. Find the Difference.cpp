class Solution {
public:
    char findTheDifference(string s, string t) {
        int freq[26] = {0};
        for (char &ch : s){
            freq[ch - 'a']++;
        }

        for (char &ch : t){
            if (freq[ch - 'a'] == 0) return ch;
            freq[ch - 'a']--;
        }

        return 0;
    }
};