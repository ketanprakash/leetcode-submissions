class Solution {
public:
    int helper(int idx, vector<int> &nums, vector<int> &dp){
        if (idx == nums.size()) return 0;
        if (idx == nums.size() - 1) return nums.back();

        if (dp[idx] != -1) return dp[idx];
        return dp[idx] = max(nums[idx] + helper(idx + 2, nums, dp), helper(idx + 1, nums, dp));
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1);
        
        dp[n] = 0, dp[n - 1] = nums.back();

        for (int i = n - 2; i >= 0; i--){
            dp[i] = max(nums[i] + dp[i + 2], dp[i + 1]);
        }

        return dp[0];
    }
};