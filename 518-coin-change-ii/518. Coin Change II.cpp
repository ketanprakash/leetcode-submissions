class Solution {
public:
    int helper(int amount, int n, vector<int> &coins, vector<vector<int>> &dp){
        if (amount < 0) return 0;
        if (amount == 0) return 1;
        if (n == 0) return 0;

        if (dp[amount][n] != -1) return dp[amount][n];
        int take = helper(amount - coins[n - 1], n, coins, dp);
        int notTake = helper(amount, n - 1, coins, dp);

        return dp[amount][n] = take + notTake;
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(amount + 1, vector<int>(coins.size() + 1, -1));
        return helper(amount, coins.size(), coins, dp);
    }
};