class Solution {
public:
    void subsets(vector<int> &nums, int idx, vector<int> &curr, vector<vector<int>> &ans){
        if (idx == nums.size()){
            ans.push_back(curr);
            return;
        }
        
        subsets(nums, idx + 1, curr, ans);

        curr.push_back(nums[idx]);
        subsets(nums, idx + 1, curr, ans);
        curr.pop_back(); 
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr; 
        vector<vector<int>> ans;

        subsets(nums, 0, curr, ans);

        return ans;
    }
};