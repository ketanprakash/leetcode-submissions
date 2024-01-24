class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (target > nums.back()) return nums.size();

        int s = 0, e = nums.size() - 1, m, ans = -1;  

        while (s <= e){
            m = s + (e - s) / 2;

            if (nums[m] >= target){
                ans = m; 
                e = m - 1;
            }
            else {
                s = m + 1;
            }
        }

        return ans;
    }
};