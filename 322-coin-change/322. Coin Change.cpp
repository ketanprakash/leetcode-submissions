class Solution {
public:
    int helper(int n, vector<int> &coins, int amount, vector<vector<int>> &dp){
        if (dp[n][amount] != -1) return dp[n][amount];
        if (amount == 0) return 0;
        if (n == 0) return -1;

        int notTake = helper(n - 1, coins, amount, dp), take = -1;

        if (coins[n - 1] <= amount) {
            take = helper(n, coins, amount - coins[n - 1], dp);
            if (take != -1) take++;
        }

        if (take == -1) return notTake;
        
        if (notTake == -1) return take;

        return dp[n][amount] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        sort(coins.begin(), coins.end());
        vector<int> prev(amount + 1);
        vector<int> curr(amount + 1);

        prev[0] = 0; curr[0] = 0;
        for (int i = 1; i <= amount; i++) prev[i] = 1e6;

        int take, notTake;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= amount; j++){
                take = 1e6, notTake = 1e6;
                notTake = prev[j];
                if (coins[i - 1] <= j) take = 1 + curr[j - coins[i - 1]];

                curr[j] = min(take, notTake);
            }
            prev = curr;
        }

        return curr[amount] >= 1e6 ? -1 : curr[amount];
    }
};