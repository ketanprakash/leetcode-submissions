class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int ans = -1;
        int firstIdx[26];
        int lastIdx[26];
        for (int &x : firstIdx) x = -1;
        for (int &x : lastIdx) x = -1;
        
        for (int i = 0; i < s.size(); i++){
            char ch = s[i];
            if (firstIdx[ch - 'a'] == -1) firstIdx[ch - 'a'] = i;
            lastIdx[ch - 'a'] = i;

        }
        
        for (int i = 0; i < 26; i++){
            if (firstIdx[i] != lastIdx[i]) ans = max(ans, lastIdx[i] - firstIdx[i] - 1);
        }

        return ans;
    }
};