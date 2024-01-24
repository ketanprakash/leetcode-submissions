class Solution {
public:
    bool checkPalindrome(string &s){
        int i = 0, j = s.size() - 1; 
        while (i < j){
            if (s[i] != s[j]) return false;
            i++; j--;
        }

        return true;
    }

    int helper(string &s, string &s1, string &s2, int idx){
        if (idx == s.size()){
            if (checkPalindrome(s1) && checkPalindrome(s2)) return s1.size() * s2.size();
            return 0;
        }

        s1.push_back(s[idx]);
        int a1 = helper(s, s1, s2, idx + 1);
        s1.pop_back();

        s2.push_back(s[idx]);
        int a2 = helper(s, s1, s2, idx + 1);
        s2.pop_back();

        int a3 = helper(s, s1, s2, idx + 1);

        return max({a1, a2, a3});
    }

    int maxProduct(string s) {
        string s1, s2;
        return helper(s, s1, s2, 0);
    }
};