class Solution {
public:
    int helper(vector<int> &nums, int n, int currSum, int target, int sum, vector<vector<int>> &dp){
        if (currSum == target && n == 0) return 1;
        if (n == 0) return 0;
        if (dp[n][sum + currSum] != -1) return dp[n][sum + currSum];
        int minus = helper(nums, n - 1, currSum - nums[n - 1], target, sum, dp);
        int plus = helper(nums, n - 1, currSum + nums[n - 1], target, sum, dp);

        return dp[n][sum + currSum] = minus + plus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        vector<vector<int>> dp(n + 1, vector<int>(2 * sum + 1, -1));
        return helper(nums, nums.size(), 0, target, sum, dp);
    }
};