class Solution {
public:
    bool helper(string &s, string &p, int n, int m, vector<vector<int>> &dp){
        if (n == 0 && m == 0) return true;
        if (m == 0) return false;
        
        if (dp[n][m] != -1) return dp[n][m];
        if (n > 0 && (s[n - 1] == p[m - 1] || p[m - 1] == '.')) return dp[n][m] = helper(s, p, n - 1, m - 1, dp);
        
        if (p[m - 1] == '*'){
            if (helper(s, p, n, m - 2, dp)) return dp[n][m] = true;
        if (n > 0 && (s[n - 1] == p[m - 2] || p[m - 2] == '.') && helper(s, p, n - 1, m, dp)) return dp[n][m] = true;
         

        }
        return dp[n][m] = false;

    }
    
    bool isMatch(string s, string p){
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, -1));
        return helper(s, p, s.size(), p.size(), dp);
    }
};