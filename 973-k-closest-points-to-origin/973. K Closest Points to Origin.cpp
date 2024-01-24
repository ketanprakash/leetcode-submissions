class Solution {
public:
    int func(int x, int y){
        return x * x + y * y;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<long long, int>> q; 
        int x, y;
        for (int i = 0; i < points.size(); i++){
            x = points[i][0], y = points[i][1];
            q.push({func(x, y), i});

            if (q.size() > k) q.pop();
        }

        vector<vector<int>> ans;

        while (!q.empty()){
            ans.push_back(points[q.top().second]);
            q.pop();
        }

        return ans;
    }
};