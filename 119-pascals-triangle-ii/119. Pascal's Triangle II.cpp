class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> vv(2);
        vv[0] = vector<int>(rowIndex + 1);
        vv[1] = vector<int>(rowIndex + 1);

        vv[0][0] = 1;

        for (int i = 1; i <= rowIndex; i++){
            vv[i % 2][0] = 1; vv[i % 2][i] = 1;
            for (int j = 1; j < i; j++){
                vv[i % 2][j] = vv[(i - 1) % 2][j - 1] + vv[(i - 1) % 2][j];
            }
        }

        return vv[rowIndex % 2];
    }
};