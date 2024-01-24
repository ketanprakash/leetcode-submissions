class Solution {
public:
    int helper(int idx, vector<int> &days, vector<int> &costs, vector<int> &dp){
        if (idx == days.size()) return 0; 

        if (dp[idx] != -1) return dp[idx];
        int ans = INT_MAX, nextIdx;
        //1 day
        nextIdx = upper_bound(days.begin() + idx, days.end(), days[idx]) - days.begin();
        ans = min(ans, costs[0] + helper(nextIdx, days, costs, dp));

        //7 days
        nextIdx = upper_bound(days.begin() + idx, days.end(), days[idx] + 6) - days.begin();
        ans = min(ans, costs[1] + helper(nextIdx, days, costs, dp));

        //30 days
        nextIdx = upper_bound(days.begin() + idx, days.end(), days[idx] + 29) - days.begin();
        ans = min(ans, costs[2] + helper(nextIdx, days, costs, dp));

        return dp[idx] = ans;
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int dp[n + 1];
        dp[n] = 0;

        for (int i = n - 1; i >= 0; i--){
            dp[i] = INT_MAX;
            int nextIdx;
            nextIdx = upper_bound(days.begin() + i, days.end(), days[i]) - days.begin(); 
            dp[i] = min(dp[i], costs[0] + dp[nextIdx]);

            nextIdx = upper_bound(days.begin() + i, days.end(), days[i] + 6) - days.begin(); 
            dp[i] = min(dp[i], costs[1] + dp[nextIdx]);

            nextIdx = upper_bound(days.begin() + i, days.end(), days[i] + 29) - days.begin(); 
            dp[i] = min(dp[i], costs[2] + dp[nextIdx]);
        }

        return dp[0];
    }
};