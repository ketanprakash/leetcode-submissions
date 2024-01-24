class Solution {
public:
    int helper(vector<int> &nums, int start, int end, vector<vector<int>> &dp) {
        if (start > end) return 0;
        if (dp[start][end] != -1) return dp[start][end];
        int mx = INT_MIN;
        for (int i = start; i <= end; i++){
            int cost1 = helper(nums, start, i - 1, dp);
            int cost2 = helper(nums, i + 1, end, dp);
            int cost3 = nums[i] * nums[start - 1] * nums[end + 1];
            mx = max(cost1 + cost2 + cost3, mx);
        }

        return dp[start][end] = mx;
    }

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(nums.size() - 1, vector<int>(nums.size() - 1, - 1));
        return helper(nums, 1, nums.size() - 2, dp);
    }
};