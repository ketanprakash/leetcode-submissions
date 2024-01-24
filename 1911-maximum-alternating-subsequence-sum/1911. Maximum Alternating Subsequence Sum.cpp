class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size(), i;
        long long x = 0, y = 0, temp_x, temp_y;

        for (i = n - 1; i >= 0; i--){
            temp_x = max(y - nums[i], x);
            temp_y = max(x + nums[i], y);
            x = temp_x, y = temp_y;
        }

        return y;
    }
};