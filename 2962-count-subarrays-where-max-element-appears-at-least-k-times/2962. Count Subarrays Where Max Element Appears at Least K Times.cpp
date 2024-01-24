class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        int count = 0; 
        int s = 0, e = -1; 
        long long ans = 0;
        
        while (true){
            while (e < n - 1 && count < k){
                count += nums[++e] == mx ? 1 : 0;
            }
            if (count < k) break;
            ans += n - e; 
            count -= nums[s++] == mx ? 1 : 0;
        }
        
        return ans;
    }
};