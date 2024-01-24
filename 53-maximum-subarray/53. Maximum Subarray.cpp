class Solution {
public:
    int kadane(vector<int> &nums){
        int currSum = 0, maxSum = 0;
        for (int i = 0; i < nums.size(); i++){
            if (currSum + nums[i] < 0){
                currSum = 0;
            }
            else currSum += nums[i];
            maxSum = max(currSum, maxSum);
        }

        return maxSum;
    }

    int maxSubArray(vector<int>& nums) {
        int mx = INT_MIN;
        for (int i = 0; i < nums.size(); i++){
            mx = max(nums[i], mx);
            if (nums[i] >= 0) return kadane(nums);
        }

        return mx;
    }
};