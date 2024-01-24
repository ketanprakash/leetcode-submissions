class Solution {
public:
    bool helper(string &s, string &p, int n, int m, vector<vector<int>> &dp){

        if (n < 0) return false;

        if (n == 0 && m == 0) return true;
        
        if (m == 0) return false;
        if (dp[n][m] != -1) return dp[n][m];
        
        if ((n > 0 && s[n - 1] == p[m - 1]) || p[m - 1] == '?') return dp[n][m] = helper(s, p, n - 1, m - 1, dp);
        
        if (p[m - 1] == '*') {
            return dp[n][m] = helper(s, p, n - 1, m, dp) || helper(s, p, n, m - 1, dp);
        }


        return dp[n][m] = false;
    }
    
    bool isMatch(string s, string p) {       
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return helper(s, p, n, m, dp); 
    }
};