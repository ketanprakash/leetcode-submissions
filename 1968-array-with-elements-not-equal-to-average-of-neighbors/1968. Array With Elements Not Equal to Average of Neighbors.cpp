class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i += 2){
            if (i + 1 <= nums.size() - 1) swap(nums[i], nums[i + 1]);
        }

        return nums;
    }
};