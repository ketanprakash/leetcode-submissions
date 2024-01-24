class Solution {
public:
    int arraySign(vector<int>& nums) {
        int sign = 1, i;
        for (i = 0; i < nums.size(); i++){
            if (nums[i] == 0) return 0;
            if (nums[i] < 0) sign = -sign;
        }

        return sign;
    }
};