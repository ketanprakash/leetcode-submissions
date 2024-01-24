class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int lis[nums.size()];
        int n = 0;
        
        for (int i = 0; i < nums.size(); i++){

            int idx = lower_bound(lis, lis + n, nums[i]) - lis;
            
            if (idx == n) lis[n++] = nums[i];
            else lis[idx] = nums[i];
        }
        
        return n;
    }
};