class Solution {
public:
    int helper(vector<string> &strs, int m, int n, int idx, vector<vector<vector<int>>> &dp){
        if (idx == 0) {
            return 0;
        }

        if (dp[m][n][idx] != -1) return dp[m][n][idx];

        int count0 = 0, count1 = 0;
        for (char &ch : strs[idx - 1]){
            if (ch == '0') count0++;
            else count1++;
        }

        if (m >= count0 && n >= count1){
            return dp[m][n][idx] = max(1 + helper(strs, m - count0, n - count1, idx - 1, dp), helper(strs, m, n, idx - 1, dp));
        }

        return dp[m][n][idx] = helper(strs, m, n, idx - 1, dp);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(strs.size() + 1, -1)));
        return helper(strs, m, n, strs.size(), dp);
    }
};