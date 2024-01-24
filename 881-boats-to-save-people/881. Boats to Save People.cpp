class Solution {
public:
    int numRescueBoats(vector<int>& nums, int limit) {
        sort(nums.begin(), nums.end());

        int s = 0, e = nums.size() - 1;
        int count = 0;
        while (s <= e){
            if (nums[s] + nums[e] <= limit){
                s++;
                e--;
            }
            else e--;
            count++;
        }

        return count;
    }
};