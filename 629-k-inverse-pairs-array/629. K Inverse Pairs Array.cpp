class Solution {
public:
    int mod = 1e9 + 7;
    int helper(int n, int k, vector<vector<int>> &dp){
        if (k < 0) return 0;
        if (k == 0) return 1;
        if (n == 0) return 0;

        if (dp[n][k] != -1) return dp[n][k];
        int ans = 0;
        for (int i = max(1, n - k); i <= n; i++){
            ans = (ans +  helper(n - 1, k - n + i, dp) % mod) % mod;
        }

        return dp[n][k] = ans;
    }

    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        return helper(n, k, dp);
    }
};