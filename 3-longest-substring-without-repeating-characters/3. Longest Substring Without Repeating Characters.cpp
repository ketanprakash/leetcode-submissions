class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        int maxLength = 1;
        int start = 0;
        unordered_map<char, int> m;
        m[s[0]] = 0;

        for (int i = 1; i < s.size(); i++){
            if (m.count(s[i]) && m[s[i]] >= start){
                start = m[s[i]] + 1;
            }
            maxLength = max(i - start + 1, maxLength);
            m[s[i]] = i;
        }

        return maxLength;
    }
};