class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        if (nums.size() <= 1) return nums;
        int n = nums.size();
        vector<int> prefixSum(nums.size()), suffixSum(nums.size());
        prefixSum[0] = nums[0];
        suffixSum.back() = nums.back();
        for (int i = 1; i < nums.size(); i++){
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        for (int i = nums.size() - 2; i >= 0; i--){
            suffixSum[i] = suffixSum[i + 1] + nums[i];
        }
        int val;
        nums[0] = suffixSum[1] - nums[0] * (n - 1);
        nums.back() = nums[nums.size() - 1] * (nums.size() - 1) - prefixSum[prefixSum.size() - 2];
        for (int i = 1; i < nums.size() - 1; i++){
            nums[i] = (nums[i] * i - prefixSum[i - 1]) + (suffixSum[i + 1] - nums[i] * (n - i - 1));
        }

        return nums;
    }
};