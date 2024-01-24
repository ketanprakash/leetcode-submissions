class Solution {
public:
    int helper(string &s1, string &s2, int n, int m, vector<vector<int>> &dp){
        if (n == 0 && m == 0) return 0;

        if (dp[n][m] != -1) return dp[n][m];
        if (n > 0 && m > 0 && s1[n - 1] == s2[m - 1]){
            return dp[n][m] = helper(s1, s2, n - 1, m - 1, dp);
        }

        int ans = INT_MAX;
        if (n > 0){
            ans = min(ans, s1[n - 1] + helper(s1, s2, n - 1, m, dp));
        }

        if (m > 0){
            ans = min(ans, s2[m - 1] + helper(s1, s2, n, m - 1, dp));
        }

        return dp[n][m] = ans;
    }

    int minimumDeleteSum(string &s1, string &s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return helper(s1, s2, s1.size(), s2.size(), dp);
    }
};