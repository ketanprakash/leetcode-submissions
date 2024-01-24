class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;
        int n = matrix.size(), m = matrix[0].size();
        int row = 0, col = m - 1;
        
        while (row < n && col >= 0){
            if (target == matrix[row][col]) return true;
            else if (target > matrix[row][col]) row++;
            else col--;
        }
        
        return false;
    }
};