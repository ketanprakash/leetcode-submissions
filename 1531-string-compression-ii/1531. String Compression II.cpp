class Solution {
public:
    int helper(string &s, int idx, char prev, int count, int k, vector<vector<vector<vector<int>>>> &dp){
        if (idx == s.size()){
            return 0;
        }


        if (dp[idx][prev][count][k] != -1) return dp[idx][prev][count][k];
        int ans = INT_MAX;

        //remove
        if (k > 0){
            ans = min(ans, helper(s, idx + 1, prev, count, k - 1, dp));
        }

        //don't remove
        if (prev != s[idx] - 'a'){
            ans = min(ans, 1 + helper(s, idx + 1, s[idx] - 'a', 1, k, dp));
        }
        else if (prev == s[idx] - 'a'){
            if (count == 1 || count == 9){
                ans = min(ans, 1 + helper(s, idx + 1, s[idx] - 'a', min(count + 1, 10), k, dp));
            }
            else {
                ans = min(ans, helper(s, idx + 1, s[idx] - 'a', min(count + 1, 10), k, dp));
            }
        }

        return dp[idx][prev][count][k] = ans;
    }

    int getLengthOfOptimalCompression(string s, int k) {
        if (s.size() == k) return 0;
        bool flag = true;  
        for (int i = 1; i < s.size(); i++){
            if (s[i] != s[i - 1]) flag = false;
        }
        if (flag) return 1 + (s.size() - k > 1 ? to_string(s.size() - k).size() : 0);

        int n = s.size(); 
        vector<vector<vector<vector<int>>>> dp(n + 1, vector<vector<vector<int>>>(27, vector<vector<int>>(11, vector<int>(k + 1, -1))));
        return helper(s, 0, 26, 0, k, dp);
    }
};