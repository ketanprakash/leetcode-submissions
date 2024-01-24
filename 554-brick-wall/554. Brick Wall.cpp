class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size();
        unordered_map<int, int> m; 

        for (int i = 0; i < n; i++){
            int pos = 0; 

            for (int j = 0; j < wall[i].size() - 1; j++){
                pos += wall[i][j];
                m[pos]++;
            }
        }

        int maxm = 0; 

        for (auto p : m){
            maxm = max(maxm, p.second);
        }

        return n - maxm;
    }
};