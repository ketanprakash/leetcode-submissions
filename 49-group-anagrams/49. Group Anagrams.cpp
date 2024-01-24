class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;

        string str; 
        for (int i = 0; i < strs.size(); i++){
            str = strs[i];
            sort(str.begin(), str.end());
            m[str].push_back(strs[i]);
        }

        vector<vector<string>> ans; 

        for (auto s : m){
            ans.push_back(s.second);
        }

        return ans;
    }
};