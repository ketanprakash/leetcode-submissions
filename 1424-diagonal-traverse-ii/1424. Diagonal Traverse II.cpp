class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int rows = nums.size(), cols = 0; 
        for (int i = 0; i < nums.size(); i++) cols = max((int)nums[i].size(), cols);
        vector<vector<int>> diagonals(rows + cols);
        for (int i = nums.size() - 1; i >= 0; i--){
            for (int j = 0; j < nums[i].size(); j++){
                diagonals[i + j].push_back(nums[i][j]);
            }
        }
        vector<int> ans; 
        for (int i = 0; i < diagonals.size(); i++){
            for (int j = 0; j < diagonals[i].size(); j++){
                ans.push_back(diagonals[i][j]);
            }
        }

        return ans;
    }
};