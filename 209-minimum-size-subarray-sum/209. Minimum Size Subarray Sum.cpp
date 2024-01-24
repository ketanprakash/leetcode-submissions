class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int s = 0, e = -1; 
        int sum = 0, ans = 0;

        while (e + 1 < n){
            sum += nums[e + 1];
            e++;
            while (sum >= target){
                ans = ans == 0 ? e - s + 1 : min(ans, e - s + 1);
                sum -= nums[s];
                s++;
            }
        }

        return ans;
    }
};