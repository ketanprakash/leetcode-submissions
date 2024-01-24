class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_set<int> s;
        for (int i = 1; i <= n * n; i++) s.insert(i);
        
        vector<int> v;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (s.count(grid[i][j])) s.erase(grid[i][j]);
                else v.push_back(grid[i][j]);
            }
        }
        v.push_back(*s.begin());
        
        return v;
    }
};