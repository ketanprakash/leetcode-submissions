class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return {};
        int sr = 0, er = matrix.size() - 1, sc = 0, ec = matrix[0].size() - 1;

        vector<int> ans;
        while (sr <= er && sc <= ec){
            for (int i = sc; i <= ec; i++){
                ans.push_back(matrix[sr][i]);
            }
            if (++sr > er) break;

            for (int i = sr; i <= er; i++){
                ans.push_back(matrix[i][ec]);
            }
            if (sc > --ec) break;

            for (int i = ec; i >= sc; i--){
                ans.push_back(matrix[er][i]);
            }
            if (sr > --er) break;

            for (int i = er; i >= sr; i--){
                ans.push_back(matrix[i][sc]);
            }
            if (++sc > ec) break;
        }

        return ans;
    }
};