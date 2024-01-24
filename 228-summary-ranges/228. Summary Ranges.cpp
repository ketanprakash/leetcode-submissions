class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() == 0) return {};
        vector<string> ans;
        int start = 0, end = 0; 

        for (int i = 0; i < nums.size(); i++){
            if (i == nums.size() - 1 || nums[i + 1] != nums[i] + 1){
                if (start != end) ans.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
                else ans.push_back(to_string(nums[start]));
                start = i + 1;
                end = i + 1;
            }
            else end++;
        }

        return ans;
    }
};