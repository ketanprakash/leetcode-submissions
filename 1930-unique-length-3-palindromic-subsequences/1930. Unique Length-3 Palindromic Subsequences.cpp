class Solution {
public:
    pair<int, int> findMinMax(vector<int> &v){
        int minm = v[0], maxm = v[0];
        
        for (int i = 0; i < v.size(); i++){
            minm = min(minm, v[i]);
            maxm = max(maxm, v[i]);
        }

        return {minm, maxm};
    }

    int countPalindromicSubsequence(string str) {
        unordered_map<char, vector<int>> m; 
        unordered_set<char> s; 

        for (int i = 0; i < str.size(); i++){
            m[str[i]].push_back(i);
        }

        int count = 0;

        for (auto p : m){
            auto p2 = findMinMax(p.second);
            int minm = p2.first, maxm = p2.second;
            s.clear();

            for (int i = minm + 1; i <= maxm - 1; i++){
                s.insert(str[i]);
            }
            count += s.size();
        }

        return count;
    }
};