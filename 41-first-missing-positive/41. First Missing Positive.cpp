class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int k = 1; 
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++){
            if (k == nums[i] && nums[i] >= 1) k++;
        }

        return k;
    }
};