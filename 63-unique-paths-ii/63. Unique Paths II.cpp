class Solution {
public:
    int helper(vector<vector<int>> &obstacleGrid, int x, int y, vector<vector<int>> &dp){
        if (x < 0 || y < 0 || obstacleGrid[x][y] == 1) return 0; 
        if (x == 0 && y == 0) return 1;

        if (dp[x][y] != -1) return dp[x][y];
        return dp[x][y] = helper(obstacleGrid, x - 1, y, dp) + helper(obstacleGrid, x, y - 1, dp);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 0) return 0; 
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();

        int dp[m];
        
        for (int i = 0; i < m; i++){
            if (obstacleGrid[0][i] == 1) dp[i] = 0;
            else dp[i] = i - 1 >= 0 ? dp[i - 1] : 1;
        }
        
        for (int i = 1; i < n; i++){
            if (obstacleGrid[i][0] == 1) dp[0] = 0;
            for (int j = 1; j < m; j++){
                if (obstacleGrid[i][j] == 1) dp[j] = 0;
                else dp[j] = dp[j] + dp[j - 1];
            }
        }

        return dp[m - 1];
    }
};