class Solution {
public:
    bool helper(string &s, vector<string> &wordDict, int idx, vector<int> &dp){
        if (idx == s.size()) return true;

        if (dp[idx] != -1) return dp[idx];
        for (string &word : wordDict){
            if (word == s.substr(idx, word.size())) {
                if (helper(s, wordDict, idx + word.size(), dp)) return dp[idx] = true;
            }
        }

        return dp[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        bool dp[n + 1];

        dp[n] = true;
        for (int i = 0; i < n; i++) dp[i] = false;

        for (int i = n - 1; i >= 0; i--){
            for (string &word : wordDict){
                if (word == s.substr(i, word.size())){
                    if (dp[i + word.size()]) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }

        return dp[0];
    }
};