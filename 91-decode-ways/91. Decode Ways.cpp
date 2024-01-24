class Solution {
public:
    int helper(string &s, int idx, vector<int> &dp){
        if (idx == s.size()) return 1;
        if (s[idx] == '0') return 0;
        if (idx == s.size() - 1) return 1;

        if (dp[idx] != -1) return dp[idx];
        int ans = helper(s, idx + 1, dp);

        if ((s[idx] - '0') * 10 + (s[idx + 1] - '0') <= 26) ans += helper(s, idx + 2, dp);

        return dp[idx] = ans;
    }

    int numDecodings(string s) {
        vector<int> dp(s.size() - 1, -1);
        return helper(s, 0, dp);
    }
};