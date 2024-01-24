class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0; 
        int x, y; 

        for (int i = 1; i < points.size(); i++){
            x = points[i][0] - points[i - 1][0];
            y = points[i][1] - points[i - 1][1];

            ans += max(abs(x), abs(y));
        }

        return ans;
    }
};