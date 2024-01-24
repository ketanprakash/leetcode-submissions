class NumMatrix {
public: 
    vector<vector<int>> prefixSum;

    NumMatrix(vector<vector<int>>& matrix) {
        prefixSum = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size()));

        prefixSum[0][0] = matrix[0][0];
        for (int i = 1; i < matrix.size(); i++){
            prefixSum[i][0] = prefixSum[i - 1][0] + matrix[i][0];
        }

        for (int i = 1; i < matrix[0].size(); i++){
            prefixSum[0][i] = prefixSum[0][i - 1] + matrix[0][i];
        }

        for (int i = 1; i < matrix.size(); i++){
            for (int j = 1; j < matrix[0].size(); j++){
                prefixSum[i][j] = prefixSum[i][j - 1] + prefixSum[i - 1][j] - prefixSum[i - 1][j - 1] + matrix[i][j];
            }
        }

        // for (int i = 0; i < matrix.size(); i++){
        //     for (int j = 0; j < matrix[0].size(); j++){
        //         cout << prefixSum[i][j] << " ";
        //     }
        //     cout << endl;
        // }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 == 0 && col1 == 0){
            return prefixSum[row2][col2];
        }
        else if (row1 == 0){
            return prefixSum[row2][col2] - prefixSum[row2][col1 - 1];
        }
        else if (col1 == 0){
            return prefixSum[row2][col2] - prefixSum[row1 - 1][col2];
        }
        return prefixSum[row2][col2] - prefixSum[row2][col1 - 1] - prefixSum[row1 - 1][col2] + prefixSum[row1 - 1][col1 - 1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */