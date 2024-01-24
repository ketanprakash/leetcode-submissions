class Solution {
public:
    int mod = 1e9 + 7;
    int helper(int n, int k, int target, vector<vector<int>> &dp){
        if (target < 0) return 0;
        if (target == 0 && n == 0) return 1;
        if (n == 0) return 0;

        if (dp[n][target] != -1) return dp[n][target];
        int count = 0;
        for (int i = 1; i <= k; i++){
            count = (count % mod + helper(n - 1, k, target - i, dp) % mod) % mod;
        }

        return dp[n][target] = count;
    }

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return helper(n, k, target, dp);
    }
};