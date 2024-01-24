class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;

        int n = matrix.size(), m = matrix[0].size();

        int s = 0, e = m * n - 1, mid, row, col;

        while (s <= e){
            mid = s + (e - s) / 2;
            
            row = mid / m;
            col = mid % m;
            
            if (matrix[row][col] == target){
                return true;
            }
            else if (target > matrix[row][col]){
                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
        }

        return false;
    }
};