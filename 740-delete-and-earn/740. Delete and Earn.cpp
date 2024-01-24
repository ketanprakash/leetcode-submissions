class Solution {
public:
    int helper(vector<int> &nums, int idx, vector<int> &dp){
        if (idx == nums.size()) return 0;
        if (dp[idx] != -1) return dp[idx];
        int lastIdx = upper_bound(nums.begin() + idx, nums.end(), nums[idx]) - nums.begin(); 
        int nextIdx = upper_bound(nums.begin() + idx, nums.end(), nums[idx] + 1) - nums.begin();
        int points = nums[idx] * (lastIdx - idx);
        
        return dp[idx] = max(points + helper(nums, nextIdx, dp), helper(nums, idx + 1, dp));
    }

    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int dp[n + 1];
        dp[n] = 0;

        int points, nextIdx, lastIdx;
        for (int i = n - 1; i >= 0; i--){
            lastIdx = upper_bound(nums.begin() + i, nums.end(), nums[i]) - nums.begin();
            nextIdx = upper_bound(nums.begin() + i, nums.end(), nums[i] + 1) - nums.begin(); 

            points = nums[i] * (lastIdx - i);
            dp[i] = max(points + dp[nextIdx], dp[i + 1]);
        }

        return dp[0];
    }
};