class Solution {
public:
    bool isAnagram(string &s, string &t) {
        int freq[26] = {0};

        for (char ch : s){
            freq[ch - 'a']++;
        }

        for (char ch : t){
            freq[ch - 'a']--;
        }

        for (int &x : freq){
            if (x != 0) return false;
        }

        return true;
    }
};