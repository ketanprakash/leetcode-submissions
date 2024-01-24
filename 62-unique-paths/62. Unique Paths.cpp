class Solution {
public:
    int helper(int x, int y){
        if (x == 0 && y == 0) return 1;
        if (x < 0 || y < 0) return 0;

        return helper(x - 1, y) + helper(x, y - 1);
    }

    int uniquePaths(int n, int m) {
        int dp[m];
        for (int i = 0; i < m; i++) dp[i] = 1;
        for (int i = 1; i < n; i++){
            for (int j = 1; j < m; j++){
                dp[j] = dp[j] + dp[j - 1];
            }
        }

        return dp[m - 1];
    }
};