class Solution {
public:
    int helper(vector<int> &stoneValue, int idx, bool alice, vector<vector<int>> &dp){
        if (idx == stoneValue.size()) return 0;

        if (dp[idx][alice] != -1) return dp[idx][alice];
        //take one
        int ans;
        if (alice) ans = stoneValue[idx] + helper(stoneValue, idx + 1, !alice, dp);
        else ans = helper(stoneValue, idx + 1, !alice, dp);

        //take two
        if (idx + 1 < stoneValue.size()){
            if (alice) ans = max(ans, stoneValue[idx] + stoneValue[idx + 1] + helper(stoneValue, idx + 2, !alice, dp));
            else ans = min(ans, helper(stoneValue, idx + 2, !alice, dp));
        }

        //take three
        if (idx + 2 < stoneValue.size()){
            if (alice) ans = max(ans, stoneValue[idx] + stoneValue[idx + 1] + stoneValue[idx + 2] + helper(stoneValue, idx + 3, !alice, dp));
            else ans = min(ans, helper(stoneValue, idx + 3, !alice, dp));
        }

        return dp[idx][alice] = ans;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        vector<vector<int>> dp(stoneValue.size(), vector<int>(2, -1));

        int val = helper(stoneValue, 0, 1, dp);

        int sum = accumulate(stoneValue.begin(), stoneValue.end(), 0);

        if (val == sum - val) return "Tie";
        else if (val > sum - val) return "Alice";
        else return "Bob";
    }
};