class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0) return {};
        vector<vector<int>> ans;
        for (int i = 1; i <= numRows; i++){
            ans.push_back(vector<int>(i));
            ans[i - 1][0] = ans[i - 1][i - 1] = 1;
        }

        for (int i = 2; i <= numRows; i++){
            for (int j = 1; j <= i - 2; j++){
                ans[i - 1][j] = ans[i - 2][j - 1] + ans[i - 2][j];
            }
        }

        return ans;
    }
};