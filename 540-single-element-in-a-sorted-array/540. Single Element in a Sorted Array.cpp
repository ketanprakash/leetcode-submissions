class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int s = 0, e = nums.size() - 1, m;

        while (s <= e){
            m = s + (e - s) / 2;
            if ((m + 1 > e || nums[m + 1] != nums[m]) && (m - 1 < s || nums[m] != nums[m - 1])){
                return nums[m];
            }

            if (m + 1 <= e && nums[m + 1] == nums[m]) m++;

            if (m % 2 == 0){
                e = m - 2;
            }
            else {
                s = m + 1;
            }
        }
        return -1;
    }
};