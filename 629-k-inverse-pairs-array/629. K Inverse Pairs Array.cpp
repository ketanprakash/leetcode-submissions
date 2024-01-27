int dp[1001][1001];

class Solution {
public:
    int mod = 1e9 + 7;
    int helper(int n, int k){
        if (k < 0) return 0;
        if (k == 0) return 1;
        if (n == 0) return 0;

        if (dp[n][k] != -1) return dp[n][k];
        int ans = 0;
        for (int i = max(1, n - k); i <= n; i++){
            ans = (ans +  helper(n - 1, k - n + i) % mod) % mod;
        }

        return dp[n][k] = ans;
    }

    int kInversePairs(int n, int k) {
        memset(dp, -1, sizeof(dp));
        return helper(n, k);
    }
};