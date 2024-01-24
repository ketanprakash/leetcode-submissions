class Solution {
public:
    int helper(vector<int> &nums, int idx, int day, vector<vector<int>> &dp){
        if (idx == nums.size() && day == 0) return 0;
        if (idx == nums.size() || day == 0) return 1e9;
        if (dp[idx][day] != -1) return dp[idx][day];
        int mx = 0;
        int ans = 1e9;
        for (int i = idx; i < nums.size(); i++){
            mx = max(mx, nums[i]);
            ans = min(ans, helper(nums, i + 1, day - 1, dp) + mx);
        }
        
        return dp[idx][day] = ans;
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        vector<vector<int>> dp(jobDifficulty.size() + 1, vector<int>(d + 1, -1));
        int ans = helper(jobDifficulty, 0, d, dp);
        return ans >= 1e9 ? -1 : ans;
    }
};