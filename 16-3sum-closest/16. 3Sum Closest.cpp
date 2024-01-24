class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        int diff = INT_MAX;

        int s, e;
        for (int i = 0; i < n; i++){
            s = i + 1, e = n - 1;
            while (s < e){
                if (abs(target - nums[i] - nums[s] - nums[e]) < diff){
                    ans = nums[i] + nums[s] + nums[e];
                    diff = abs(target - nums[i] - nums[s] - nums[e]);
                }

                if (target == nums[i] + nums[s] + nums[e]){
                    return target;
                }
                else if (nums[i] + nums[s] + nums[e] < target){
                    s++;
                }
                else {
                    e--;
                }
            }
        }

        return ans;
    }
};