class Solution {
public:
    long long minDays(long long n, unordered_map<long long, long long> &dp){
        if (dp.count(n)) return dp[n];
        if (n == 0) return 0;
        if (n == 1) return 1;

        long long ans = n;

        if (n % 2 != 0 || n % 3 != 0) ans = 1 + minDays(n - 1, dp);
        if (n % 2 == 0) ans = min(ans, 1 + minDays(n - n / 2, dp));
        if (n % 3 == 0) ans = min(ans, 1 + minDays(n - 2 * n / 3, dp));

        return dp[n] = ans;
    }

    long long minDays(long long n) {
        unordered_map<long long, long long> dp;

        return minDays(n, dp);
    }
};