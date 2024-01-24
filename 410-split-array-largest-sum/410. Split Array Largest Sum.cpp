class Solution {
public:
    bool check(vector<int> &nums, int k, int sum){
        int count = 0;
        int curr = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] > sum) return false;

            if (curr + nums[i] > sum) {
                count++;
                curr = nums[i];
            }
            else {
                curr += nums[i];
            }
        }

        count++;

        return count <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int s = 0, e = accumulate(nums.begin(), nums.end(), 0), m, ans;

        while (s <= e){
            m = s + (e - s) / 2; 

            if (check(nums, k, m)){
                ans = m; 
                e = m - 1;
            }
            else {
                s = m + 1;
            }
        }

        return ans;
    }
};