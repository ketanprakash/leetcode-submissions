class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++){
            int correctIdx = nums[i] - 1;
            
            while (nums[correctIdx] != nums[i]){
                swap(nums[i], nums[correctIdx]);
                correctIdx = nums[i] - 1;
            }
        }
        
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] != i + 1){
                return {nums[i], i + 1};
            }
        }
        
        return {};
    }
};