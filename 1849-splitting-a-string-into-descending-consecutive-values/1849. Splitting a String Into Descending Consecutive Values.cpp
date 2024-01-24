class Solution {
public:
    bool splitString(string &s, int idx, string &curr, vector<string> &ans){
        if (idx == s.size()){
            if (ans.size() < 2) return false;
            for (int i = 1; i < ans.size(); i++) {
                if (stoull(ans[i]) != stoull(ans[i - 1]) - 1) return false;
            }
            return true;
        }
        curr.push_back(s[idx]);
        if (idx != s.size() - 1 && splitString(s, idx + 1, curr, ans)) return true;
        ans.push_back(curr);
        curr = "";
        if (splitString(s, idx + 1, curr, ans)) return true;
        curr = ans.back(); 
        ans.pop_back();
        curr.pop_back();

        return false;
    }

    bool splitString(string s) {
        string curr; 
        vector<string> ans;

        return splitString(s, 0, curr, ans);
    }
};