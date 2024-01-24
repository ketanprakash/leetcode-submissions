class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 1) return 1;
        int j = 0;
        
        for (int i = 0; i < nums.size(); i++){
            if (i == 0 || nums[i - 1] != nums[i]){
                nums[j++] = nums[i];
                if (i + 1 < nums.size() && nums[i] == nums[i + 1]){
                    i++; 
                    nums[j++] = nums[i];
                }
            }
        }

        return j;
    }
};