class Solution {
public:
    void combinationSum2(vector<int> &candidates, int idx, int target, vector<int> &curr, vector<vector<int>> &ans){
        if (idx == candidates.size()){
            if (target == 0) ans.push_back(curr);
            return;
        }

        if (target < 0) return;

        curr.push_back(candidates[idx]);
        combinationSum2(candidates, idx + 1, target - candidates[idx], curr, ans);
        curr.pop_back();

        if (curr.size() == 0 || curr.back() != candidates[idx]){
            combinationSum2(candidates, idx + 1, target, curr, ans);
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> curr; 
        vector<vector<int>> ans; 

        combinationSum2(candidates, 0, target, curr, ans);

        return ans;
    }
};