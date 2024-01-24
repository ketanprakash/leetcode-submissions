class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();
        int maxDiag = 0, maxArea = 0; 
        
        for (int i = 0; i < n; i++){
            int u = dimensions[i][0], v = dimensions[i][1];
            
            int diag = u * u + v * v;
            int area = u * v;
            if (diag > maxDiag) {
                maxDiag = diag;
                maxArea = area;
            }
            if (diag == maxDiag) maxArea = max(area, maxArea);
        }
        
        return maxArea;
    }
};