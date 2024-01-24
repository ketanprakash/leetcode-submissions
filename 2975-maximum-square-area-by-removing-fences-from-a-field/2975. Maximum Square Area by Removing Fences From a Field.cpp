class Solution {
public:
    int mod = 1e9 + 7;
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        long long ans = -1;
        hFences.push_back(1);
        vFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(n);
        
        unordered_set<int> distH; 
        unordered_set<int> distV;
        
        for (int i = 0; i < hFences.size() - 1; i++){
            for (int j = i + 1; j < hFences.size(); j++){
                if (i == j) continue;
                distH.insert(abs(hFences[j] - hFences[i]));
            }
        }
        
        for (int i = 0; i < vFences.size() - 1; i++){
            for (int j = i + 1; j < vFences.size(); j++){
                if (i == j) continue;
                distV.insert(abs(vFences[i] - vFences[j]));
            }
        }
        
        for (int x : distH){
            if (distV.count(x)) ans = ans == -1 ? x : max((long long)x, ans);
        }
        
        return ans == -1 ? -1 : ((ans % mod) * (ans % mod)) % mod;
    }
};