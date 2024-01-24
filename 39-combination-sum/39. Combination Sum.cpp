class Solution {
public:
    void combinationSum(vector<int> &candidates, int idx, int &currSum, vector<int> &curr, vector<vector<int>> &ans, int target){
        if (currSum > target) return;
        if (idx == candidates.size()){
            if (target == currSum) ans.push_back(curr);
            return;
        }

        curr.push_back(candidates[idx]);
        currSum += candidates[idx];
        combinationSum(candidates, idx, currSum, curr, ans, target);
        currSum -= candidates[idx];
        curr.pop_back();

        combinationSum(candidates, idx + 1, currSum, curr, ans, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int currSum = 0; 
        vector<int> curr; 
        vector<vector<int>> ans;

        combinationSum(candidates, 0, currSum, curr, ans, target);

        return ans;
    }
};