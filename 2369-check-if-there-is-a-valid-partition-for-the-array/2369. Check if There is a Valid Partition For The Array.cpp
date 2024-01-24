class Solution {
public:
    bool check(vector<int> &nums, int s, int e){
        if (e - s + 1 == 2){
            return nums[s] == nums[e];
        }

        if (e - s + 1 == 3){
            return (nums[s] == nums[e] && nums[s] == nums[s + 1]) || (nums[s] + 1 == nums[s + 1] && nums[s + 1] == nums[e] - 1);
        }

        return false;
    }

    bool helper(vector<int> &nums, int s, vector<int> &dp){
        int e = nums.size() - 1;
        if (e - s + 1 < 2) return false;

        if (dp[s] != -1) return dp[s];
        if (check(nums, s, e)) return dp[s] = true;
        if (check(nums, s, s + 1) && helper(nums, s + 2, dp)) return dp[s] = true;
        if (e - s + 1 >= 3 && check(nums, s, s + 2) && helper(nums, s + 3, dp)) return dp[s] = true;

        return dp[s] = false;
    }

    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        bool dp[n];
        for (auto &x : dp) x = false;

        int e = n - 1;
        for (int s = e - 1; s >= 0; s--){
            if (check(nums, s, e)) dp[s] = true;
            else if (check(nums, s, s + 1) && dp[s + 2]) dp[s] = true;
            else if (e - s + 1 >= 3 && check(nums, s, s + 2) && dp[s + 3]) dp[s] = true;
        }

        return dp[0];
    }
};