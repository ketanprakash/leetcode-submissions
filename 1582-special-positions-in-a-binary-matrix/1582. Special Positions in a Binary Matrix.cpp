class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        if (mat.size() == 0) return 0;
        int n = mat.size(); 
        int m = mat[0].size();

        vector<int> rows(n);
        vector<int> cols(m);

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (mat[i][j] == 1) {
                    rows[i]++; 
                    cols[j]++;
                }
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (mat[i][j] == 1 && rows[i] == 1 && cols[j] == 1) count++;
            }
        }

        return count;
    }
};