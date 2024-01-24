class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        if (nums.size() <= 2) return -1;
        
        sort(nums.begin(), nums.end());
        long long sum = nums[0] + nums[1]; 
        long long maxSum = -1;
        
        for (int i = 2; i < nums.size(); i++){
            if (sum > nums[i]) {
                maxSum = sum + nums[i];
            }
            sum += nums[i];
        }
        
        return maxSum;
    }
};