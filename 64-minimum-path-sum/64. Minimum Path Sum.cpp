class Solution {
public:
    int helper(vector<vector<int>> &grid, int x, int y, vector<vector<int>> &dp){
        if (x == 0 && y == 0){
            return grid[x][y];
        }
        if (dp[x][y] != -1) return dp[x][y];

        int ans = INT_MAX;
        
        if (x - 1 >= 0){
            ans = min(ans, grid[x][y] + helper(grid, x - 1, y, dp));
        }
        if (y - 1 >= 0){
            ans = min(ans, grid[x][y] + helper(grid, x, y - 1, dp));
        }

        return dp[x][y] = ans;
    }

    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        return helper(grid, n - 1, m - 1, dp);
    }
};