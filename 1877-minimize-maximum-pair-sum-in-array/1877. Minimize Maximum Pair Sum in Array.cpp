class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int s = 0, e = nums.size() -1;
        int ans = INT_MIN;
        while(s < e){
            ans = max(ans, nums[s] + nums[e]);
            s++;
            e--;
        }
        
        return ans;
        
    }
};