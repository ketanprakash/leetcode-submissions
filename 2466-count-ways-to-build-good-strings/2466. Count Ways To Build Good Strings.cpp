class Solution {
public:
    int mod = 1e9 + 7;
    int helper(int n, int zero, int one, vector<int> &dp){
        if (n < 0) return 0;
        if (n == 0) return 1;
        if (dp[n] != -1) return dp[n];
        return dp[n] = (helper(n - zero, zero, one, dp) % mod + helper(n - one, zero, one, dp) % mod) % mod;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        int ans = 0;
        int dp[high + 1];
        dp[0] = 1;
        for (int i = 1; i <= high; i++){
            dp[i] = 0;
            dp[i] = (dp[i] % mod + (i - zero >= 0 ? dp[i - zero] % mod : 0)) % mod;
            dp[i] = (dp[i] % mod + (i - one >= 0 ? dp[i - one] % mod : 0)) % mod;
        }

        for (int i = low; i <= high; i++){
            ans = (ans % mod + dp[i] % mod) % mod;
        }

        return ans;
    }
};