class Solution {
public:
    int helper(vector<int> &nums, int i, int mask){
        if (i == nums.size()) return 0;
        
        int ans = helper(nums, i + 1, mask);
        
        if (!(mask & nums[i])) {
            ans = max(ans, __builtin_popcount(nums[i]) + helper(nums, i + 1, mask | nums[i]));
        }
        
        return ans;
    }
    
    int maxLength(vector<string>& arr) {
        vector<int> nums;
        
        int mask, i;
        bool flag;
        for (string &str : arr){
            mask = 0;
            flag = true;
            
            for (char &ch : str){
                i = ch - 'a';
                if (mask & (1 << i)) flag = false;
                mask = mask | (1 << i);
            }
            if (flag) nums.push_back(mask);
        }
        
        return helper(nums, 0, 0);
    }
};