class Solution {
public:
    bool helper(string &s1, string &s2, string &s3, int n, int m, vector<vector<int>> &dp){
        if (m == 0 && n == 0) return true;
        if (dp[n][m] != -1) return dp[n][m];
        if (n > 0 && m > 0 && s1[n - 1] == s2[m - 1] && s1[n - 1] == s3[n + m - 1]){
            return dp[n][m] = helper(s1, s2, s3, n - 1, m, dp) || helper(s1, s2, s3, n, m - 1, dp);
        }

        if (n > 0 && s1[n - 1] == s3[n + m - 1]){
            return dp[n][m] = helper(s1, s2, s3, n - 1, m, dp);
        }

        if (m > 0 && s2[m - 1] == s3[n + m - 1]){
            return dp[n][m] = helper(s1, s2, s3, n, m - 1, dp);
        }

        return dp[n][m] = false;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;

        int n = s1.size(), m = s2.size();
        int dp[m + 1];

        dp[0] = 1;
        for (int i = 0; i <= n; i++){
            for (int j = 0; j <= m; j++){
                if (i == 0 && j == 0) continue;

                if (i > 0 && j > 0 && s1[i - 1] == s2[j - 1] && s1[i - 1] == s3[i + j - 1]){
                    dp[j] = dp[j] || dp[j - 1];
                }
                else if (i > 0 && s1[i - 1] == s3[i + j - 1]){
                    dp[j] = dp[j];
                }
                else if (j > 0 && s2[j - 1] == s3[i + j - 1]){
                    dp[j] = dp[j - 1];
                }
                else dp[j] = 0;
            }
        }

        return dp[m];
    }
};