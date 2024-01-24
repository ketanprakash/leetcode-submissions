class Solution {
public:
    int helper(vector<int> &piles, int idx, int m, bool alice, vector<vector<vector<int>>> &dp){
        if (idx == piles.size()) return 0;
        if (dp[idx][m][alice] != -1) return dp[idx][m][alice];
        int sum = 0; 
        int ans;
        if (alice) ans = 0;
        else ans = INT_MAX;
        

        for (int x = 1; x <= min(2 * m, (int)piles.size() - idx); x++){
            sum += piles[idx + x - 1];
            if (alice) ans = max(ans, sum + helper(piles, idx + x, max(m, x), 0, dp));
            else ans = min(ans, helper(piles, idx + x, max(m, x), 1, dp));
        }

        return dp[idx][m][alice] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        vector<vector<vector<int>>> dp(piles.size() + 1, vector<vector<int>>(piles.size() + 1, vector<int>(2, -1)));
        return helper(piles, 0, 1, 1, dp);
    }
};