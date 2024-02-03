class Solution {
public:
    bool helper(vector<int> &nums, int k, int mask, int rem, int target, vector<vector<int>> &dp){
        if (k == 1) return true;

        if (dp[k][mask] != -1) return dp[k][mask];
        for (int i = 0; i < nums.size(); i++){
            if (mask & (1 << i)){
                if (rem == nums[i]){
                    if (helper(nums, k - 1, mask & (~(1 << i)), target, target, dp)) return dp[k][mask] = true;
                }
                else if (rem > nums[i]){
                    if (helper(nums, k, mask & (~(1 << i)), rem - nums[i], target, dp)) return dp[k][mask] = true;
                }
            }
        }

        return dp[k][mask] = false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;

        vector<vector<int>> dp(k + 1, vector<int>(1 << (int)(nums.size()), -1));
        return helper(nums, k, (1 << (int)nums.size()) - 1, sum / k, sum / k, dp);
    }
};