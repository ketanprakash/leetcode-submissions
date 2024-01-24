class Solution {
public:
    long long nc2(int n){
        return (long long) n * (n - 1) / 2;
    }

    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double, int> m; 

        long long count = 0, hcf;

        for (int i = 0; i < rectangles.size(); i++){
            m[(double)rectangles[i][0]/rectangles[i][1]]++;
        }

        for (auto p : m){
            count += nc2(p.second);
        }

        return count;
    }
};