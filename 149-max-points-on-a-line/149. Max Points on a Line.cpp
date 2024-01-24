class Solution {
public:
    bool collinear(vector<int> &v1, vector<int> &v2, vector<int> &v3){
        int x1 = v1[0], y1 = v1[1], x2 = v2[0], y2 = v2[1], x3 = v3[0], y3 = v3[1];
        double m1 = (y2 - (double)y1) / (x2 - (double)x1);
        double m2 = (y3 - (double)y2) / (x3 - (double)x2);

        return m1 == m2;
    }

    int maxPoints(vector<vector<int>>& points) {
        int maxCount = 1;
        for (int i = 0; i < points.size(); i++){
            for (int j = i + 1; j < points.size(); j++){
                int count = 2;
                for (int k = 0; k < points.size(); k++){
                    if (k == i || k == j) continue;
                    if (collinear(points[i], points[j], points[k])) count++;
                }
                maxCount = max(count, maxCount);
            }
        }

        return maxCount;
    }
};