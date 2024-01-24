class Solution {
public:
    vector<int> dp;
    Solution(){
        dp = vector<int>(20, -1);
    }

    int numTrees(int n) {
        if (dp[n] != -1) return dp[n];
        if (n <= 1) return 1;
        int ans = 0;
        for (int i = 0; i < n; i++){
            ans += numTrees(i) * numTrees(n - i - 1);
        }

        return dp[n] = ans;
    }
};