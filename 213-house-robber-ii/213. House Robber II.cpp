class Solution {
public:
    int helper(int idx, vector<int> &nums, vector<int> &dp){
        if (idx == nums.size()) return 0;
        if (idx == nums.size() - 1) return nums.back();

        if (dp[idx] != -1) return dp[idx];
        return dp[idx] = max(helper(idx + 2, nums, dp) + nums[idx], helper(idx + 1, nums, dp));
    }

    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        vector<int> dp1(nums.size(), -1), dp2(nums.size(), -1);
        int last = nums.back(); 
        nums.pop_back();
        int ans = helper(0, nums, dp1);
        nums.push_back(last);
        ans = max(ans, helper(1, nums, dp2));

        return ans;
    }
};