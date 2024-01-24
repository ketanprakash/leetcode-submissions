class Solution {
public:
    void permute(vector<int> &nums, int idx, set<vector<int>> &ansSet){
        if (idx == nums.size()){
            ansSet.insert(nums);
            return;
        }

        for (int i = idx; i < nums.size(); i++){
            swap(nums[idx], nums[i]);
            permute(nums, idx + 1, ansSet);
            swap(nums[idx], nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ansSet; 
        vector<vector<int>> ans;

        permute(nums, 0, ansSet);
        for (auto v : ansSet){
            ans.push_back(v);
        }

        return ans;
    }
};