class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long row0 = 0; 
        for (long long i = 1; i < grid[0].size(); i++){
            row0 += grid[0][i];
        }

        long long row1 = grid[1][0];
        long long ans = row0;

        for (long long i = 1; i < grid[0].size(); i++){
            row0 -= grid[0][i];
            ans = min(ans, max(row1, row0));
            row1 += grid[1][i];
        }

        return ans;
    }
};