class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<long long, long long>> dp(n);

        long long d, ans = 0;
        for (int i = n - 2; i >= 0; i--){
            for (int j = i + 1; j < n; j++){
                d = (long long)nums[j] - nums[i];
                dp[i][d] += 1;
                if (dp[j].count(d)){
                    dp[i][d] += dp[j][d];
                    ans += dp[j][d];
                }
            }
        }

        return ans;
    }
};