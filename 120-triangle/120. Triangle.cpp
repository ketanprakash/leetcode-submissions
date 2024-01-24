class Solution {
public:
    int helper(vector<vector<int>> &triangle, int row, int col, vector<vector<int>> &dp){
        if (row == triangle.size() - 1){
            return triangle[row][col];
        }

        if (dp[row][col] != -1) return dp[row][col];
        return dp[row][col] = triangle[row][col] + min(helper(triangle, row + 1, col, dp), helper(triangle, row + 1, col + 1, dp));
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        int dp[n];
        for (int j = 0; j < n; j++) dp[j] = triangle[n - 1][j];

        for (int i = n - 2; i >= 0; i--){
            for (int j = 0; j <= i; j++){
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
            }
        }

        return dp[0];
    }
};