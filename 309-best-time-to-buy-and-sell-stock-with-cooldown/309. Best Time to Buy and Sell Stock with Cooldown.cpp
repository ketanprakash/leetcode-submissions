class Solution {
public:
    int helper(vector<int> &prices, int idx, bool bought, vector<vector<int>> &dp){
        if (idx >= prices.size()) return 0; 

        if (dp[idx][bought] != -1) return dp[idx][bought];
        if (bought){
            //can sell
            int sell = helper(prices, idx + 2, 0, dp) + prices[idx];
            int notSell = helper(prices, idx + 1, 1, dp);

            return dp[idx][bought] = max(sell, notSell);
        }
        else {
            //can buy
            int buy = helper(prices, idx + 1, 1, dp) - prices[idx];
            int notBuy = helper(prices, idx + 1, 0, dp);

            return dp[idx][bought] = max(buy, notBuy);
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));
        return helper(prices, 0, 0, dp);
    }
};