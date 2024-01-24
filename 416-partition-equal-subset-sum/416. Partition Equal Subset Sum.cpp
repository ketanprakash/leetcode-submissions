class Solution {
public:
    bool helper(vector<int> &nums, int n, int sum, vector<vector<int>> &dp){
        if (sum < 0) return false;
        if (sum == 0){
            return true;
        }
        if (n == 0){
            return false;
        }

        if (dp[n][sum] != -1) return dp[n][sum];
        return dp[n][sum] = helper(nums, n - 1, sum - nums[n - 1], dp) || helper(nums, n - 1, sum, dp);
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2 != 0) return false;
        sum /= 2;

        bool *prev = new bool[sum + 1];
        bool *curr = new bool[sum + 1];

        for (int i = 0; i <= sum; i++) curr[i] = false;
        for (int i = 0; i <= sum; i++) prev[i] = false;

        prev[0] = true;
        curr[0] = true;

        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= sum; j++){
                curr[j] = false;
                if (j >= nums[i - 1]) curr[j] = curr[j] || prev[j - nums[i - 1]];
                curr[j] = curr[j] || prev[j];
            }
            swap(prev, curr);
        }

        return curr[sum];
    }
};