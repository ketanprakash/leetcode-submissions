class Solution {
public:
    void rev(vector<int> &nums, int s, int e){
        while (s < e){
            swap(nums[s++], nums[e--]);
        }
    }

    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2; 
    
        while (i >= 0){
            if (nums[i] >= nums[i + 1]) i--;
            else {
                int j = nums.size() - 1; 
                while (nums[j] <= nums[i]) j--; 
                swap(nums[i], nums[j]);
                rev(nums, i + 1, nums.size() - 1);
                return;
            }
        }

        rev(nums, 0, nums.size() - 1);
    }
};