class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        bool firstColZero = false, firstRowZero = false;
        for (int i = 0; i < rows; i++){
            if (matrix[i][0] == 0) firstColZero = true;
        }
        for (int j = 0; j < cols; j++){
            if (matrix[0][j] == 0) firstRowZero = true;
        }
        for (int i = 1; i < rows; i++){
            for (int j = 1; j < cols; j++){
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < rows; i++){
            for (int j = 1; j < cols; j++){
                if (matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        for (int i = 0; i < rows; i++){
            if (firstColZero) matrix[i][0] = 0;
        }

        for (int j = 0; j < cols; j++){
            if (firstRowZero) matrix[0][j] = 0;
        }
    }
};