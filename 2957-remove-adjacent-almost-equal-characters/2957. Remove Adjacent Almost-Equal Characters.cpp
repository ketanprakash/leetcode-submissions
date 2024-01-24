class Solution {
public:
    int helper(string &word, int prev, int idx, vector<vector<int>> &dp){
        if (idx == word.size()) return 0; 
        
        if (dp[prev][idx] != -1) return dp[prev][idx];
        int ans = INT_MAX;
        if (abs(word[idx] - 'a' - prev) <= 1) ans = min(ans, 1 + helper(word, 28, idx + 1, dp));
        else if (idx + 1 < word.size() && abs(word[idx] - word[idx + 1]) <= 1) {
            ans = min({ans, 1 + helper(word, 28, idx + 1, dp), helper(word, word[idx] - 'a', idx + 1, dp)});
        }
        else {
            ans = min(ans, helper(word, word[idx] - 'a', idx + 1, dp));
        }
                      
        return dp[prev][idx] = ans;
    }
    
    int removeAlmostEqualCharacters(string word) {
        vector<vector<int>> dp(29, vector<int>(word.size(), -1));
        return helper(word, 28, 0, dp);
    }
};