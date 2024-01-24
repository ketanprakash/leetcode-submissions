class Solution {
public:
    int helper(int n, vector<int> &dp){
        if (n == 0) return 0;
        if (dp[n] != -1) return dp[n];
        int ans = 1e6;
        for (int i = 1; i <= sqrt(n); i++){
            ans = min(ans, 1 + helper(n - i * i, dp));
        }

        return dp[n] = ans;
    }

    int numSquares(int n) {
        int dp[n + 1];
        dp[0] = 0;
        for (int i = 1; i <= n; i++){
            dp[i] = 1e6;
            for (int j = 1; j <= sqrt(i); j++){
                dp[i] = min(dp[i], 1 + dp[i - j * j]);
            }
        }

        return dp[n];
    }
};