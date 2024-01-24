class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;
        
        vector<int> freq1(26);
        vector<int> freq2(26);

        for (int i = 0; i < word1.size(); i++){
            freq1[word1[i] - 'a']++;
            freq2[word2[i] - 'a']++;
        }
        
        for (int i = 0; i < 26; i++){
            if (freq1[i] && !freq2[i]) return false;
            if (freq2[i] && !freq1[i]) return false;
        }
        
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());
        
        return freq1 == freq2;
    }
};