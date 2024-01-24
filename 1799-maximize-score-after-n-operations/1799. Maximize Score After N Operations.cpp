class Solution {
public:
    int helper(vector<int> &nums, int mask, vector<int> &dp){
        if (mask == 0) return 0;
        if (dp[mask] != -1) return dp[mask];
        int t = __builtin_popcount(mask) / 2;

        int ans = INT_MIN;
        for (int i = 0; i < nums.size(); i++){
            for (int j = i + 1; j < nums.size(); j++){
                if (((mask >> i) & 1) && ((mask >> j) & 1)){
                    ans = max(ans, t * __gcd(nums[i], nums[j]) + helper(nums, mask ^ (1 << i) ^ (1 << j), dp));
                }
            }
        }

        return dp[mask] = ans;
    }

    int maxScore(vector<int>& nums) {
        int n = nums.size(); 
        int mask = (1 << n) - 1;
        vector<int> dp(mask + 1, -1);

        return helper(nums, mask, dp);
    }
};