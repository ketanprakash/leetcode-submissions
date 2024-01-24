class Solution {
public:
    int helper(int n, vector<int> &nums, int curr, int target, vector<vector<int>> &dp){
        if (n == 0) return curr;
        if (dp[n][curr] != -1) return dp[n][curr];
        int ans = 0;
        if (curr + nums[n - 1] <= target) ans = max(ans, helper(n - 1, nums, curr + nums[n - 1], target, dp));

        ans = max(ans, helper(n - 1, nums, curr, target, dp));

        return dp[n][curr] = ans;
    }

    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        vector<vector<int>> dp(stones.size() + 1, vector<int>(sum / 2 + 1, -1));

        int firstSet = helper(stones.size(), stones, 0, sum / 2, dp);
        return sum - 2 * firstSet;
    }
};