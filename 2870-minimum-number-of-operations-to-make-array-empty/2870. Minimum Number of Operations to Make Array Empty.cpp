class Solution {
public:

    
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int i = 0;
        int ub, lb, count;
        int ans = 0;
        while (i < n) {
            ub = upper_bound(nums.begin(), nums.end(), nums[i]) - nums.begin();
            lb = lower_bound(nums.begin(), nums.end(), nums[i]) - nums.begin();
            
            count = ub - lb;
            if (count == 1) return -1;
            if (count % 3 == 0) ans += count / 3;
            else ans += count / 3 + 1;



      
            i = ub;
        }
        
        return ans;
            
    }
};