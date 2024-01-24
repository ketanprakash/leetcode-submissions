class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        int freq[26] = {0};
        
        for (auto &s : words){
            for (auto &ch : s){
                freq[ch - 'a']++;
            }
        }
        
        for (auto &x : freq){
            if (x % n != 0) return false;
        }

        return true;
    }
};