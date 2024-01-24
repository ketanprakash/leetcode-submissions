class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1, -1};
        int firstIdx = -1, lastIdx = nums.size();
        int s = 0, e = nums.size() - 1, m, ans;

        while (s <= e){
            m = s + (e - s) / 2;

            if (nums[m] >= target){
                firstIdx = m;
                e = m - 1;
            }
            else {
                s = m + 1;
            }
        }
        s = 0, e = nums.size() - 1;

        while (s <= e){
            m = s + (e - s) / 2; 

            if (nums[m] > target){
                lastIdx = m; 
                e = m - 1;
            }
            else {
                s = m + 1;
            }
        }

        lastIdx--;
        if (firstIdx >= nums.size() || nums[firstIdx] != target) {
            firstIdx = -1, lastIdx = -1;
        }

        return {firstIdx, lastIdx};
    }
};