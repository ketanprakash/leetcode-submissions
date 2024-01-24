class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        vector<vector<int>> count(n + 1, vector<int>(n + 1));    

        for (int i = 0; i <= n; i++) {
            dp[0][i] = 0;
            count[0][i] = 1;
        }

        int take, notTake;

        for (int i = 1; i <= n; i++){
            for (int j = i; j <= n; j++){
                if (j == n || nums[i - 1] < nums[j]){
                    take = 1 + dp[i - 1][i - 1];
                    notTake = dp[i - 1][j];

                    if (take == notTake){
                        dp[i][j] = take;
                        count[i][j] = count[i - 1][i - 1] + count[i - 1][j];
                    }
                    else if (take > notTake){
                        dp[i][j] = take;
                        count[i][j] = count[i - 1][i - 1];
                    }
                    else {
                        dp[i][j] = dp[i - 1][j];
                        count[i][j] = count[i - 1][j];
                    }
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                    count[i][j] = count[i - 1][j];
                }
            }
        }
        cout << dp[n][n] << endl;
        return count[n][n];
    }
};