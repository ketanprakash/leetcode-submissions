class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if (nums[0] > nums.back()) reverse(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 1; i++){
            if (nums[i + 1] < nums[i]) return false;
        }

        return true;
    }
};