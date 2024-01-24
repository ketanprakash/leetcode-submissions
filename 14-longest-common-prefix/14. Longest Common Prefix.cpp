class Solution {
public:
    string helper(string &str1, string &str2){
        string str; 
        for (int i = 0; i < str1.size(); i++){
            if (i < str2.size() && str1[i] == str2[i]) str.push_back(str1[i]);
            else break;
        }

        return str;
    }

    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        string ans = strs[0];

        for (int i = 1; i < strs.size(); i++){
            ans = helper(ans, strs[i]);
        }

        return ans;
    }
};