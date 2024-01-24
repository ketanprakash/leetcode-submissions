class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int n = nums.size();
        int s = 0, e = nums.size() - 1, m, ans;

        while (s <= e){
            m = s + (e - s) / 2;
            
            if ((m - 1 < 0 || nums[m] >= nums[m - 1]) && (m + 1 > n - 1 || nums[m] >= nums[m + 1])){
                return m;
            }
            if (nums[m] < nums[m + 1]){
                s = m + 1;
            }
            else {
                e = m - 1;
            }
        }

        return 0;
    }
};