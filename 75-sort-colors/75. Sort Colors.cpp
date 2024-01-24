class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n - 1; 

        for (int k = 0; k <= j; k++){
            if (nums[k] == 0){
                swap(nums[k], nums[i++]);
            }
            else if (nums[k] == 2){
                swap(nums[k], nums[j--]);
                k--;
            }
        }
    }
};