class Solution {
public:
    int helper(vector<pair<int, int>> &players, int n, int lastAge, vector<vector<int>> &dp){
        if (n == 0) return 0;
        if (dp[n][lastAge] != -1) return dp[n][lastAge]; 
        auto &[score, age] = players[n - 1];

        int take = 0, notTake = 0;
        if (age <= lastAge){
            take = score + helper(players, n - 1, age, dp);
        }

        notTake = helper(players, n - 1, lastAge, dp);

        return dp[n][lastAge] = max(take, notTake);
    }

    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = ages.size();
        vector<pair<int, int>> players;
        for (int i = 0; i < ages.size(); i++) players.push_back({scores[i], ages[i]});
        sort(players.begin(), players.end());
        int maxAge = *max_element(ages.begin(), ages.end());

        vector<vector<int>> dp(n + 1, vector<int>(maxAge + 1, -1));

        return helper(players, n, maxAge, dp);
    }
};