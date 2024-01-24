class Solution {
public:
    int atmost(vector<int> &nums, int goal){
        int sum = 0; 
        int s = 0, e = 0; 
        int ans = 0; 

        while (e < nums.size()){
            sum += nums[e];

            while (sum > goal && s <= e){
                sum -= nums[s];
                s++;
            }

            ans += e - s + 1;

            e++;
        }

        return ans;
    }

    int atleast(vector<int> &nums, int goal){
        if (goal == 0){
            return nums.size() * (nums.size() + 1) / 2;
        }
        int sum = 0; 
        int s = 0, e = 0; 
        int ans = 0; 

        while (e < nums.size()){
            sum += nums[e];

            while (sum - nums[s] >= goal){
                sum -= nums[s];
                s++;
            }

            if (sum == goal) ans += s + 1;

            e++;
        }

        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atleast(nums, goal) - atleast(nums, goal + 1);
    }
};