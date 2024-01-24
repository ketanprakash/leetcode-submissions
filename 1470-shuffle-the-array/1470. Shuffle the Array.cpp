class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        for (int i = 0; i < 2 * n; i++){
            nums[i] = nums[i] << 10;
        }

        for (int i = 0; i < 2 * n; i += 2){
            nums[i] = nums[i] | (nums[i / 2] >> 10);
            nums[i + 1] = nums[i + 1] | (nums[n + i / 2] >> 10);
        }

        for (int i = 0; i < 2 * n; i++){
            nums[i] = nums[i] & 1023;
        }

        return nums;
    }
};