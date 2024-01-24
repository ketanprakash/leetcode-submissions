class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int mx = INT_MIN, secondMx = INT_MIN, mn = INT_MAX, secondMn = INT_MAX; 
        int n = nums.size();

        for (int i = 0; i < n; i++){
            if (mx < nums[i]){
                secondMx = mx; 
                mx = nums[i];
            }
            else if (secondMx < nums[i]){
                secondMx = nums[i];
            }

            if (mn > nums[i]){
                secondMn = mn; 
                mn = nums[i];
            }
            else if (secondMn > nums[i]){
                secondMn = nums[i];
            }
        }

        return mx * secondMx - mn * secondMn;
    }
};