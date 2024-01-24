class Solution {
public:
    vector<int> findAnagrams(string &s, string &p) {
        if (p.size() > s.size()) return {};
        vector<int> window(26);
        vector<int> freq(26);
        vector<int> ans;

        for (int i = 0; i < p.size(); i++){
            freq[p[i] - 'a']++;
        }

        for (int i = 0; i < p.size(); i++){
            window[s[i] - 'a']++;
        }

        if (window == freq) ans.push_back(0);

        for (int i = 1; i <= s.size() - p.size(); i++){
            window[s[i - 1] - 'a']--;
            window[s[i + p.size() - 1] - 'a']++;
            if (window == freq) ans.push_back(i);
        }

        return ans;
    }
};