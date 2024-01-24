class Solution {
public:
    vector<vector<bool>> palindrome;
    vector<int> dp;

    int helper(string &str, int idx){
        if (idx >= str.size() || palindrome[idx][str.size() - 1]) return 0;
        if (dp[idx] != -1) return dp[idx];
        int ans = INT_MAX;
        for (int i = idx; i < str.size(); i++){
            if (palindrome[idx][i]) {
                ans = min(ans, 1 + helper(str, i + 1));
            }
        }

        return dp[idx] = ans;
    }

    int minCut(string &str) {
        int n = str.size();
        palindrome = vector<vector<bool>>(n, vector<bool>(n, false));
        dp = vector<int>(n, -1);

        int s, e;
        for (int i = 0; i < n; i++){
            s = i, e = i; 
            while (s >= 0 && e < n){
                if (str[s] == str[e]) palindrome[s][e] = true;
                else break;
                s--; e++;
            }

            s = i, e = i + 1;
            while (s >= 0 && e < n){
                if (str[s] == str[e]) palindrome[s][e] = true;
                else break;
                s--; e++;
            }
        }

        return helper(str, 0);
    }
};