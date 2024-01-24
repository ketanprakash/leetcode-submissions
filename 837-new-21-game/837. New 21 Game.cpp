class Solution {
public:
    double helper(int curr, int n, int k, int maxPts){
        if (curr >= k && curr <= n) return 1;
        if (curr >= k) return 0;
        double prob = 0;
        for (int i = 1; i <= maxPts; i++){
            prob += helper(curr + i, n, k, maxPts) / maxPts;
        }

        return prob;
    }

    double new21Game(int n, int k, int maxPts) {
        if (n >= k + maxPts - 1) return 1;
        vector<double> dp(k + maxPts);
        double nextMaxPtsSum = 0;
        for (int i = n; i >= k; i--){
            dp[i] = 1;
            nextMaxPtsSum += 1;
        }

        for (int i = k - 1; i >= 0; i--){
            dp[i] = nextMaxPtsSum / maxPts;
            nextMaxPtsSum -= dp[i + maxPts];
            nextMaxPtsSum += dp[i];
        }

        return dp[0];
    }
};