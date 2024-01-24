class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) return 0;
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        int ans = 0;

        int dc[] = {0, 1, 1};
        int dr[] = {1, 0, 1};

        for (int i = n - 1; i >= 0; i--){
            for (int j = m - 1; j >= 0; j--){
                if (matrix[i][j] == '0') continue;

                dp[i][j] = INT_MAX;
                for (int x = 0; x < 3; x++){
                    if (i + dr[x] >= n || j + dc[x] >= m) {dp[i][j] = 0;
                    continue;}
                    dp[i][j] = min(dp[i][j], dp[i + dr[x]][j + dc[x]]);
                }
                dp[i][j]++;
                ans = max(dp[i][j], ans);
            }
        }

        return ans * ans;
    }
};