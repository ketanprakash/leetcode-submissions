class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int count = 1, ans = 0;

        for (int i = 1; i <= n; i++){
            if (i == n || nums[i - 1] != nums[i]){
                ans += (count * (count - 1)) / 2;
                count = 1;
            }
            else count++;
        }

        return ans;
    }
};