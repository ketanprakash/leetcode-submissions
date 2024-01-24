class Solution {
public:
    int helper(vector<int> &cuts, int startCutIdx, int endCutIdx, vector<vector<int>> &dp){
        if (startCutIdx >= endCutIdx - 1) return 0;

        if (dp[startCutIdx][endCutIdx] != -1) return dp[startCutIdx][endCutIdx];
        int len = cuts[endCutIdx] - cuts[startCutIdx];

        int mn = INT_MAX;
        for (int cut = startCutIdx + 1; cut < endCutIdx; cut++){
            int cost1 = helper(cuts, startCutIdx, cut, dp);
            int cost2 = helper(cuts, cut, endCutIdx, dp);
            mn = min(cost1 + cost2, mn);
        }

        return dp[startCutIdx][endCutIdx] = mn + len;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(cuts.size(), vector<int>(cuts.size(), -1));

        return helper(cuts, 0, cuts.size() - 1, dp);
    }
};