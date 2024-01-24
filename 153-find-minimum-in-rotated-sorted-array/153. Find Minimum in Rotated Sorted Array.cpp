class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0, e = nums.size() - 1, m;

        while (s <= e){
            m = s + (e - s) / 2; 

            if ((m - 1 < s || nums[m - 1] >= nums[m]) && (m + 1 > e || nums[m + 1] >= nums[m])){
                return nums[m];
            }

            if (nums[m] >= nums[s] && nums[m] >= nums[e]){
                s = m + 1;
            }
            else {
                e = m - 1;
            }
        }

        return nums[0];
    }
};