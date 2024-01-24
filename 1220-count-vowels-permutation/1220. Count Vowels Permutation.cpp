class Solution {
public:
    int mod = 1e9 + 7;
    int countVowelPermutation(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(5, 0));
        for (int i = 0; i < 5; i++) dp[1][i] = 1;

        for (int i = 2; i <= n; i++){
            dp[i][0] = dp[i - 1][1] % mod;
            dp[i][1] = (dp[i - 1][0] % mod + dp[i - 1][2] % mod) % mod;
            dp[i][2] = ((dp[i - 1][0] % mod + dp[i - 1][1] % mod) % mod + (dp[i - 1][3] % mod + dp[i - 1][4] % mod) % mod) % mod;
            dp[i][3] = (dp[i - 1][2] % mod + dp[i - 1][4] % mod) % mod;
            dp[i][4] = dp[i - 1][0] % mod;
        }

        int ans = 0;

        for (int i = 0; i < 5; i++){
            ans = (ans % mod + dp[n][i] % mod) % mod;
        }

        return ans;
    }
};