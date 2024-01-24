class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        vector<vector<int>> v = mat;
        k = k % mat[0].size();
        for (int i = 0; i < mat.size(); i++){
            reverse(v[i].begin(), v[i].end());
            
            if (i % 2 != 0){
                reverse(v[i].begin(), v[i].begin() + k);
                reverse(v[i].begin() + k, v[i].end());
            }
            else {
                reverse(v[i].begin(), v[i].begin() + mat[i].size() - k);
                reverse(v[i].begin() + mat[i].size() - k, v[i].end());
            }
        }
        
        for (int i = 0; i < mat.size(); i++){
            for (int j = 0; j < mat[i].size(); j++){
                if (v[i][j] != mat[i][j]) return false;
            }
        }
        
        return true;
    }
};