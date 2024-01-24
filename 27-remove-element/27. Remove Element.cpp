class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, k = nums.size();
        for (i = 0; i < k; i++){
            if (nums[i] == val){
                nums[i] = nums[k - 1];
                k--;
                i--;
            }
        }

        return k;
    }
};