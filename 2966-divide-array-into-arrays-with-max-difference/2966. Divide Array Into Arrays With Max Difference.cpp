class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        if (nums.size() % 3 != 0) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); i += 3){
            if (nums[i + 2] - nums[i] <= k) {
                vector<int> v; 
                for (int j = i; j <= i + 2; j++) v.push_back(nums[j]);
                ans.push_back(v);
            }
            else return {};
        }
        
        return ans;
    }
};