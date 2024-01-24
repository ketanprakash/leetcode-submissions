class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 1;
        int s = 0, e = 0; 
        long long sum = nums[0];

        while (e + 1 < n){
            sum += (long long)nums[e + 1];
            e++;
            while ((e - s + 1) * (long long)nums[e] - sum > k){
                sum -= nums[s++];
            }
            ans = max(ans, e - s + 1);
        }

        return ans;
    }
};