class Solution {
public:
    int helper(int s, int e, vector<int> &piles, vector<vector<int>> &dp){
        if (s > e) return 0;
        if (dp[s][e] != -1) return dp[s][e];
        if ((e - s + 1) % 2 == 0) {
            return dp[s][e] = max(helper(s + 1, e, piles, dp) + piles[s], helper(s, e - 1, piles, dp) + piles[e]);
        }

        return dp[s][e] = min(helper(s + 1, e, piles, dp), helper(s, e - 1, piles, dp));
    }

    bool stoneGame(vector<int>& piles) {
        vector<vector<int>> dp(piles.size(), vector<int>(piles.size(), -1));
        int ans = helper(0, piles.size() - 1, piles, dp);
        int sum = accumulate(piles.begin(), piles.end(), 0);
        return ans > sum / 2;
    }
};