class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int i = 0, n = nums.size(); 

        while (i < n){
            int rightIdx = nums[i] - 1; 
            
            if (nums[rightIdx] != nums[i]){
                swap(nums[rightIdx], nums[i]);
            }
            else i++;
        }

        vector<int> ans;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] != i + 1){
                ans.push_back(i + 1);
            }
        }

        return ans;
    }
};