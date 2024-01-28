class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return 0;
        int n = matrix.size(); 
        int m = matrix[0].size(); 

        //calculate prefix sum for every row
        for (int row = 0; row < n; row++){
            for (int col = 1; col < m; col++){
                matrix[row][col] = matrix[row][col - 1] + matrix[row][col];
            }
        }
        int ans = 0;
        for (int col1 = 0; col1 < m; col1++){
            for (int col2 = col1; col2 < m; col2++){
                unordered_map<int, int> m;
                m[0] = 1;
                int sum = 0;
                for (int row = 0; row < n; row++){
                    sum += matrix[row][col2] - (col1 - 1 >= 0 ? matrix[row][col1 - 1] : 0);
                    if (m.count(sum - target)) ans += m[sum - target];
                    m[sum]++;
                }
            }
        }

        return ans;
    }
};