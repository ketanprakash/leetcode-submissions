class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> outdegree;

        string u, v;
        for (int i = 0; i < paths.size(); i++){
            u = paths[i][0], v = paths[i][1];
            if (outdegree.count(u) == 0) outdegree[u] = 0;
            if (outdegree.count(v) == 0) outdegree[v] = 0;
            outdegree[u]++;
        }

        for (auto &[city, out] : outdegree){
            if (out == 0) return city;
        }

        return "";
    }
};