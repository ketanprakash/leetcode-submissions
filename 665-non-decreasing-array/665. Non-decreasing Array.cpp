class Solution {
public:
    bool check(vector<int> &nums){
        for (int i = 0; i < nums.size() - 1; i++){
            if (nums[i] > nums[i + 1]) {
                return false;
            }
        }

        return true;
    }

    bool checkPossibility(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++){
            if (nums[i] > nums[i + 1]){
                int tmp = nums[i];
                nums[i] = nums[i + 1];
                if(check(nums)) return true;

                nums[i] = tmp;
                nums[i + 1] = tmp;

                if (check(nums)) return true;

                return false;
            }
        }

        return true;
    }
};