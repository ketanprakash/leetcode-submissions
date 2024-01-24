class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        int s = 0, e = -1;
        int ans = 0;
        
        while (e < n - 1){
            while (e < n - 1){
                if (freq[nums[e + 1]] == k) break;
                e++; 
                freq[nums[e]]++;
            }
            
            ans = max(e - s + 1, ans);
            freq[nums[s++]]--;
        }
        
        return ans;
    }
};