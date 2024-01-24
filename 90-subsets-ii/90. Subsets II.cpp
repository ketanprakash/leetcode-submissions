class Solution {
public:
    void subsets(vector<int> &nums, int idx, vector<int> &curr, vector<vector<int>> &ans){
        if (idx == nums.size()){
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[idx]);
        subsets(nums, idx + 1, curr, ans);
        curr.pop_back();
        if (curr.size() == 0 || curr.back() != nums[idx]){
            subsets(nums, idx + 1, curr, ans);
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> curr; 
        vector<vector<int>> ans; 

        subsets(nums, 0, curr, ans);

        return ans;
    }
};