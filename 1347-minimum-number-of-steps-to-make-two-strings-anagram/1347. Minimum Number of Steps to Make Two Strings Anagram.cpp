class Solution {
public:
    int minSteps(string s, string t) {

        int freq[26] = {0};
        
        for (char &ch : s) freq[ch - 'a']++;
        
        for (char &ch : t){
            if (freq[ch - 'a'] > 0) freq[ch - 'a']--; 
        }
        
        return accumulate(freq, freq + 26, 0);
    }
};