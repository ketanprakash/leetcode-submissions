class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        long long dist[26][26];
        long long ans = 0;
        for (int i = 0; i < 26; i++){
            for (int j = 0; j < 26; j++){
                if (i == j) dist[i][j] = 0;
                else dist[i][j] = -1;
            }
        }
        
        for (int i = 0; i < original.size(); i++){
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            
            if (dist[u][v] == -1 || dist[u][v] > cost[i]){
                dist[u][v] = cost[i];
            }
        }
        for (int k = 0; k < 26; k++){
            for (int i = 0; i < 26; i++){
                for (int j = 0; j < 26; j++){
                        if (dist[i][k] == -1 || dist[k][j] == -1) continue;
                        if (dist[i][j] == -1 || dist[i][j] > dist[i][k] + dist[k][j]) {
                            dist[i][j] = dist[i][k] + dist[k][j];
                        }
                }
            }            
        }

        
        for (int i = 0; i < source.size(); i++){
            int u = source[i] - 'a';
            int v = target[i] - 'a';
            if (dist[u][v] == -1) return -1;
            ans += dist[u][v];
        }
        
        return ans;
    }
};