class Solution {
public:
    int helper(vector<int> &nums1, vector<int> &num2, int n, int m, vector<vector<int>> &dp){
        if (n == 0 || m == 0) return 0; 

        if (dp[n][m] != -1) return dp[n][m];

        if (nums1[n - 1] == num2[m - 1]){
            return dp[n][m] = 1 + helper(nums1, num2, n - 1, m - 1, dp);
        }

        return dp[n][m] = max(helper(nums1, num2, n - 1, m, dp), helper(nums1, num2, n, m - 1, dp));
    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(); 
        int m = nums2.size(); 
        int *prev = new int[m + 1];
        int *curr = new int[m + 1];

        for (int i = 0; i <= m; i++) prev[i] = 0;
        for (int i = 0; i <= m; i++) curr[i] = 0;

        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if (nums1[i - 1] == nums2[j - 1]){
                    curr[j] = 1 + prev[j - 1];
                    continue;
                }
                curr[j] = max(prev[j], curr[j - 1]);
            }
            swap(prev, curr);
        }

        return prev[m];
    }
};