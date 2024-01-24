class Solution {
public:
    int helper(vector<int> &nums, int target, vector<int> &dp){
        if (target == 0) return 1;

        if (dp[target] != -1) return dp[target];
        int ans = 0;
        for (int &num : nums){
            if (num > target) continue;
            ans += helper(nums, target - num, dp);
        }

        return dp[target] = ans;
    }

    int combinationSum4(vector<int>& nums, int target) {
        unsigned int dp[target + 1];
        dp[0] = 1;

        for (int i = 1; i <= target; i++){
            dp[i] = 0;
            for (int &num : nums){
                if (num > i) continue;
                dp[i] = dp[i] + dp[i - num];
            }
        }

        return dp[target];
    }
};