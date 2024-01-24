class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int sr = 0, er = n - 1, sc = 0, ec = n - 1; 
        
        int x = 1;
        while (sr <= er && sc <= ec){
            for (int i = sc; i <= ec; i++){
                ans[sr][i] = x++;
            }
            sr++; 
            if (sr > er) break;

            for (int i = sr; i <= er; i++){
                ans[i][ec] = x++;
            }
            ec--;
            if (sc > ec) break;

            for (int i = ec; i >= sc; i--){
                ans[er][i] = x++;
            }
            er--;
            if (sr > er) break;

            for (int i = er; i >= sr; i--){
                ans[i][sc] = x++;
            }
            sc++;
        }

        return ans;
    }
};