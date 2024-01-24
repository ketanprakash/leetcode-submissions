class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        if (grid.size() == 0) return {};
        int n = grid.size(), m = grid[0].size();
        vector<int> zerosRow(n), zerosCol(m), onesRow(n), onesCol(m);

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 0) {
                    zerosRow[i]++;
                    zerosCol[j]++;
                }
                else {
                    onesRow[i]++;
                    onesCol[j]++;
                }
            }
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                grid[i][j] = onesRow[i] + onesCol[j] - zerosRow[i] - zerosCol[j];
            }
        }

        return grid;
    }
};