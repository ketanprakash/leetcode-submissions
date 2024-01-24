class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 0; 

        for (int i = 0; i < nums.size(); i++){
            if (i + 1 == nums.size() || nums[i] != nums[i + 1]){
                swap(nums[i], nums[j++]);
            }
        }

        return j;
    }
};