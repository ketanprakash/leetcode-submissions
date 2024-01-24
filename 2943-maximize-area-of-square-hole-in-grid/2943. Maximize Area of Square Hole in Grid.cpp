class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hbars, vector<int>& vbars) {
        hbars.push_back(1);
        hbars.push_back(n + 2);
        vbars.push_back(1);
        vbars.push_back(m + 2);

        unordered_set<int> s;
        for (int i = 0; i < hbars.size(); i++){
            for (int j = i + 1; j < hbars.size(); j++){
                s.insert(abs(hbars[i] - hbars[j]));
            }
        }

        int ans = 0;

        for (int i = 0; i < vbars.size(); i++){
            for (int j = i + 1; j < vbars.size(); j++){
                if (ans < abs(vbars[i] - vbars[j]) && s.count(abs(vbars[i] - vbars[j]))){
                    ans = abs(vbars[i] - vbars[j]);
                }
            }
        }

        return ans * ans;
    }
};