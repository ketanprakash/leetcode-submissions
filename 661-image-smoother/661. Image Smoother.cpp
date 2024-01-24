class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        if (img.size() == 0) return {};
        int n = img.size(), m = img[0].size();
        int total, count, row, col;
        vector<vector<int>> ans(n, vector<int>(m));

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                int count = 0, total = 0;
                for (int x = -1; x <= 1; x++){
                    for (int y = -1; y <= 1; y++){
                        row = i + x, col = j + y;
                        if (row < 0 || col < 0 || row >= n || col >= m) continue;
                        count++; total += img[row][col];
                    }
                }
                ans[i][j] = total / count;
            }
        }

        return ans;
    }
};