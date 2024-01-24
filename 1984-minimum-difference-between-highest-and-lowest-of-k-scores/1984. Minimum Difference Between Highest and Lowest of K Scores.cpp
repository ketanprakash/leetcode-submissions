class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int i = 0, j = k - 1; 
        int minm = INT_MAX;

        for (; j < nums.size(); j++){
            minm = min(minm, nums[j] - nums[i]);
            i++;
        }

        return minm;
    }
};