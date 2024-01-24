class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> freq(26), f;
        for (char ch : chars) freq[ch - 'a']++;

        int ans = 0; 
        bool flag;
        for (int i = 0; i < words.size(); i++){
            f = freq;
            flag = true;
            for (char ch : words[i]) {
                f[ch - 'a']--;
                if (f[ch - 'a'] < 0) flag = false;
            }
            if (flag) ans += words[i].size(); 
        }

        return ans;
    }
};