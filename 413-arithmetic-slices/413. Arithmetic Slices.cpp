class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n - 1; i++){
            int s = i, e = i + 1, d = nums[e] - nums[s];

            while (e < n - 1){
                if (nums[e + 1] - nums[e] == d){
                    e++;
                    ans++;
                }
                else break;
            } 
        }

        return ans;
    }
};