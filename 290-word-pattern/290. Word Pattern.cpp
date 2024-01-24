class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> v; 

        string word;
        for (int i = 0; i < s.size(); i++){
            if (s[i] != ' ') {
                word.push_back(s[i]);
            }
            else {
                v.push_back(word);
                word = "";
            }
        }
        v.push_back(word);

        unordered_map<char, string> m1; 
        unordered_map<string, char> m2;

        if (v.size() != pattern.size()) return false;

        for (int i = 0; i < v.size(); i++){
            if ((m1.count(pattern[i]) == 0 && m2.count(v[i]) == 0) || (m1[pattern[i]] == v[i] && m2[v[i]] == pattern[i])){
                m1[pattern[i]] = v[i];
                m2[v[i]] = pattern[i];
            }
            else return false;
        }

        return true;
    }
};