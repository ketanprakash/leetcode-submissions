class Solution {
public:
    int helper(string &s1, string &s2, int n, int m, vector<vector<int>> &dp){
        if (n == 0 || m == 0) return 0; 

        if (dp[n][m] != -1) return dp[n][m];

        if (s1[n - 1] == s2[m - 1]) return dp[n][m] = 1 + helper(s1, s2, n - 1, m - 1, dp);

        return dp[n][m] = max(helper(s1, s2, n - 1, m, dp), helper(s1, s2, n, m - 1, dp));
    }

    int longestPalindromeSubseq(string s) {
        string s1 = s;
        reverse(s1.begin(), s1.end());

        int n = s.size();
        int *prev = new int[s.size() + 1];
        int *curr = new int[s.size() + 1];

        for (int i = 0; i <= s.size(); i++) prev[i] = 0; 
        for (int i = 0; i <= s.size(); i++) curr[i] = 0;

        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if (s[i - 1] == s1[j - 1]) curr[j] = 1 + prev[j - 1];
                else {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            swap(prev, curr);
        }

        return prev[n];
    }
};