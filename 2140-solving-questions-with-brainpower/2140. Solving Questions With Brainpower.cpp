class Solution {
public:
    long long helper(int idx, vector<vector<int>> &questions, vector<long long> &dp){
        if (idx >= questions.size()){
            return 0;
        }
        if (dp[idx] != -1) return dp[idx];
        long long take = questions[idx][0] + helper(idx + questions[idx][1] + 1, questions, dp);
        long long notTake = helper(idx + 1, questions, dp);

        return dp[idx] = max(take, notTake);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        long long dp[n];
        for (int i = 0; i < n; i++) dp[i] = 0;
        for (int i = n - 1; i >= 0; i--){
            dp[i] = max(dp[i], questions[i][0] + (i + questions[i][1] + 1 < n ? dp[i + questions[i][1] + 1] : 0));
            dp[i] = max(dp[i], (i + 1 < n ? dp[i + 1] : 0));
        }

        return dp[0];
    }
};