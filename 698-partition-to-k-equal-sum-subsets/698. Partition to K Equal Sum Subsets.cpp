class Solution {
public:
    bool canPartitionKSubsets(vector<int> &nums, int k, int curr_sum, int target, int idx, vector<bool> &visited){
        if (k == 1) return true;
        if (idx == nums.size()) return false;
        if (curr_sum == target){
            return canPartitionKSubsets(nums, k - 1, 0, target, 0, visited);
        }

        if (!visited[idx] && curr_sum + nums[idx] <= target){
            visited[idx] = true;
            if (canPartitionKSubsets(nums, k, curr_sum + nums[idx], target, idx + 1, visited)) return true;
            visited[idx] = false;
        }

        if (canPartitionKSubsets(nums, k, curr_sum, target, idx + 1, visited)) return true;

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        vector<bool> visited(nums.size(), false);
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (nums.size() < k || sum % k != 0) return false;

        return canPartitionKSubsets(nums, k, 0, sum / k, 0, visited);
    }
};