class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector<int> freq(26);
        vector<int> chars(26);

        for (int i = 0; i < s1.size(); i++){
            freq[s1[i] - 'a']++;
        }

        for (int i = 0; i < s1.size(); i++){
            chars[s2[i] - 'a']++;
        }

        if (chars == freq) return true;

        int s = 0, e = s1.size() - 1; 

        while (e + 1 < s2.size()){
            chars[s2[s++] - 'a']--;
            chars[s2[e++ + 1] - 'a']++;

            if (chars == freq) return true;
        }

        return false;
    }
};