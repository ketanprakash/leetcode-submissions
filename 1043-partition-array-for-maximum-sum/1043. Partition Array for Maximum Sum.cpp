class Solution {
public:
    int findMax(vector<int> &arr, int start, int end, int k){
        int mx = arr[start];
        for (int i = start; i <= end; i++){
            mx = max(arr[i], mx);
        }

        return mx;
    }

    int helper(vector<int> &arr, int start, int end, int k, vector<vector<int>> &dp){
        if (dp[start][end] != -1) return dp[start][end];
        if (end < start) return -1e9;
        if (end == start) return arr[start];
        if (end - start + 1 <= k){
            return findMax(arr, start, end, k) * (end - start + 1);
        }

        int mx = INT_MIN;
        for (int i = start; i < end; i++){
            int c1 = helper(arr, start, i, k, dp);
            int c2 = helper(arr, i + 1, end, k, dp);
            mx = max(c1 + c2, mx);
        }
        return dp[start][end] = mx;
    }

    int helperOptimized(vector<int> &arr, int start, int k, vector<int> &dp){
        if (start >= arr.size()) return 0;
        if (dp[start] != -1) return dp[start];

        int ans = INT_MIN;
        int mx = INT_MIN; 
        int len = 0;
        for (int i = start; i <= min(start + k - 1, (int)arr.size() - 1); i++){
            len++;
            mx = max(arr[i], mx);
            ans = max(mx * len + helperOptimized(arr, i + 1, k, dp), ans);
        }
        return dp[start] = ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(), -1);
        return helperOptimized(arr, 0, k, dp);
    }
};