class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> m;
        
        for (auto &v : matches){
            int a = v[0], b = v[1];
            
            m[a]; m[b]++;
        }
        
        vector<vector<int>> ans(2);
        
        for (auto &p : m){
            if (p.second == 0) ans[0].push_back(p.first);
            if (p.second == 1) ans[1].push_back(p.first);
        }
        
        sort(ans[0].begin(), ans[0].end());
        
        sort(ans[1].begin(), ans[1].end());
        
        return ans;
    }
};