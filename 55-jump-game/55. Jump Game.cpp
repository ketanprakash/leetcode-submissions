class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReached = 0; 

        for (int i = 0; i <= maxReached; i++){
            maxReached = min((int)nums.size() - 1, max(maxReached, i + nums[i]));
        }

        return maxReached == nums.size() - 1;
    }
};