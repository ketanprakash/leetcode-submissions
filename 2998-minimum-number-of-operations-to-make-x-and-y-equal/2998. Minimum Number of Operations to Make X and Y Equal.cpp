class Solution {
public:
    int helper(int x, int y, vector<int> &dp){
        if (x == y) return 0;
        if (y > x) return y - x;
        
        if (dp[x] != -1) return dp[x];
        int ans = 1e6;
        
        ans = min({ans, x % 11 + 1 + helper(x / 11, y, dp), 11 - x % 11 + 1 + helper(x / 11 + 1, y, dp)});
        
        ans = min({ans, x % 5 + 1 + helper(x / 5, y, dp), 5 - x % 5 + 1 + helper(x / 5 + 1, y, dp)});
        
        ans = min({ans, 1 + helper(x - 1, y, dp)});
        
        return dp[x] = ans;
    }
    
    int minimumOperationsToMakeEqual(int x, int y) {
        vector<int> dp((int)1e6, -1);
        
        return helper(x, y, dp);
    }
};