class Solution {
public:
    int helper(string &word1, string &word2, int n, int m, vector<vector<int>> &dp){
        if (n == 0) return m;
        if (m == 0) return n; 

        if (dp[n][m] != -1) return dp[n][m];

        if (word1[n - 1] == word2[m - 1]) return helper(word1, word2, n - 1, m - 1, dp);

        int ansInsert = 1 + helper(word1, word2, n, m - 1, dp);

        int ansDelete = 1 + helper(word1, word2, n - 1, m, dp);

        int ansReplace = 1 + helper(word1, word2, n - 1, m - 1, dp);

        return dp[n][m] = min({ansInsert, ansDelete, ansReplace});
    }

    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size(); 
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return helper(word1, word2, word1.size(), word2.size(), dp);
    }
};