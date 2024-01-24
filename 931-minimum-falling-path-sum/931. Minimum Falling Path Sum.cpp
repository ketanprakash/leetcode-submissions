class Solution {
public:
    int helper(vector<vector<int>> &matrix, int i, int j, vector<vector<int>> &dp){
        if (i == matrix.size()) return 0;
        
        if (dp[i][j] != -1) return dp[i][j];
        
        int ans = matrix[i][j] + helper(matrix, i + 1, j, dp);
        
        if (j - 1 >= 0){
            ans = min(ans, matrix[i][j] + helper(matrix, i + 1, j - 1, dp));
        }
                      
        if (j + 1 < matrix.size()){
            ans = min(ans, matrix[i][j] + helper(matrix, i + 1, j + 1, dp));
        }
        
        return dp[i][j] = ans;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; i++){
            dp[n - 1][i] = matrix[n - 1][i];
        }

        for (int i = n - 2; i >= 0; i--){
            for (int j = 0; j < n; j++){
                dp[i][j] = matrix[i][j] + dp[i + 1][j];

                if (j + 1 < n){
                    dp[i][j] = min(dp[i][j], matrix[i][j] + dp[i + 1][j + 1]);
                }

                if (j - 1 >= 0){
                    dp[i][j] = min(dp[i][j], matrix[i][j] + dp[i + 1][j - 1]);
                }
            }
        }
        
        return *min_element(dp[0].begin(), dp[0].end());
    }
};