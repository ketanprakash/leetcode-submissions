class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m;
        unordered_set<int> s;
        
        for (auto &x : arr){
            m[x]++;
        }
        
        for (auto &[x, f] : m){
            if (s.count(f)) return false;
            
            s.insert(f);
        }
        
        return true;
    }
};