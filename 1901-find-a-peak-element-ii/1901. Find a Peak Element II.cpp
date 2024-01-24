class Solution {
public:
    int findMax(vector<int> &arr){
        int maxm = INT_MIN, max_idx = -1;
        for (int i = 0; i < arr.size(); i++){
            max_idx = maxm < arr[i] ? i : max_idx;
            maxm = max(maxm, arr[i]);
        }

        return maxm;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int s = 0, e = n - 1, m, ans;

        while (s <= e){
            m = s + (e - s) / 2;
            
            pair<int, int> x;
            if (m + 1 >= n || findMax(mat[m]) > findMax(mat[m + 1])){
                ans = m;
                e = m - 1;
            }
            else {
                s = m + 1;
            }
        }

        int max_idx = 0;
        for (int i = 1; i < mat[ans].size(); i++){
            max_idx = mat[ans][max_idx] < mat[ans][i] ? i : max_idx;
        }

        return {ans, max_idx};
    }
};