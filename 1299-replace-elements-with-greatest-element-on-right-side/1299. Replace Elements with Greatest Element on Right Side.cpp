class Solution {
public:
    vector<int> replaceElements(vector<int>& nums) {
        int rightMax = -1, val, i;

        for (i = nums.size() - 1; i >= 0; i--){
            val = nums[i];
            nums[i] = rightMax;
            rightMax = max(rightMax, val);
        }

        return nums;
    }
};