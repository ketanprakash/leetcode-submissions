class Solution {
public:
    bool checkPalindrome(string &str){
        int s = 0, e = str.size() - 1; 

        while (s < e){
            if (str[s] != str[e]) return false; 
            s++; e--;
        }

        return true;
    }

    void partition(string &s, int idx, string str, vector<string> &curr, vector<vector<string>> &ans){
        if (idx == s.size()){
            for (int i = 0; i < curr.size(); i++){
                if (!checkPalindrome(curr[i])) return;
            }
            ans.push_back(curr);
            return;
        }
        str.push_back(s[idx]);
        curr.push_back(str);
        partition(s, idx + 1, "", curr, ans);
        curr.pop_back();

        if (idx != s.size() - 1) {
            partition(s, idx + 1, str, curr, ans);
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> curr; 
        vector<vector<string>> ans; 
        partition(s, 0, "", curr, ans);

        return ans;
    }
};