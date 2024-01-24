class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        if (grid.size() == 0) return {};
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> temp(m, vector<int>(n));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                temp[j][i] = grid[i][j];
            }
        }
        int x = k / m; 
        int y = k % m;
        int s;
        for (int i = m - 1; i >= 0; i--){
            if (y-- > 0){
                s = (x + 1) % n;
            }
            else s = x % n;

            reverse(temp[i].begin(), temp[i].end());
            reverse(temp[i].begin(), temp[i].begin() + s);
            reverse(temp[i].begin() + s, temp[i].end());
        }
        k = k % m;
        reverse(temp.begin(), temp.end());
        reverse(temp.begin(), temp.begin() + k);
        reverse(temp.begin() + k, temp.end());

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                grid[i][j] = temp[j][i];
            }
        }

        return grid;
    }
};