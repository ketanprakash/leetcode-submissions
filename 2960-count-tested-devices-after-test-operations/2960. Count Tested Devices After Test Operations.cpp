class Solution {
public:
    int countTestedDevices(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++){
            if (max(0, nums[i] - count) > 0) count++;
        }
        
        return count;
    }
};