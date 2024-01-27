int dp[1001][1001];

class Solution {
public:
    int mod = 1e9 + 7;

    // helper(n, k)     = helper(n - 1, k) + helper(n - 1, k - 1) + ... helper(n - 1, k - n + 1)
    // helper(n, k - 1) =                    helper(n - 1, k - 1) + ... helper(n - 1, k - n + 1) + helper(n - 1, k - n)

    //helper(n, k) - helper(n, k - 1) = helper(n - 1, k) - helper(n - 1, k - n)
    //helper(n, k) = helper(n, k - 1) + helper(n - 1, k) - helper(n - 1, k - n)
    int helper(int n, int k){
        if (k < 0) return 0;
        if (k == 0) return 1;
        if (n == 0) return 0;

        if (dp[n][k] != -1) return dp[n][k];
        int ans = 0; 
        ans = (ans + helper(n, k - 1) % mod) % mod;
        ans = (ans + helper(n - 1, k) % mod) % mod; 
        ans = (ans - helper(n - 1, k - n) % mod + mod) % mod;

        return dp[n][k] = ans;
    }

    int kInversePairs(int n, int k) {
        memset(dp, -1, sizeof(dp));
        return helper(n, k);
    }
};