class Solution {
public:
    int kadane(vector<int> &nums, bool mn){
        int currSum = 0, maxSum = 0;

        int x = pow(-1, mn);
        for (int i = 0; i < nums.size(); i++){
            if (currSum + x * nums[i] < 0){
                currSum = 0;
            }
            else currSum += x * nums[i];

            maxSum = max(maxSum, currSum);
        }

        return x * maxSum;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int mx = INT_MIN;

        for (int i = 0; i < nums.size(); i++){
            mx = max(mx, nums[i]);
            if (nums[i] >= 0){
                int mxSubarray = kadane(nums, 0);
                int mnSubarray = kadane(nums, 1);

                return max(mxSubarray, sum - mnSubarray);
            }
        }

        return mx;
    }
};