class Solution {
public:
    bool check(vector<int> &nums, int p, int ans){
        int count = 0;
        for (int i = 0; i < nums.size() - 1; i++){
            if (nums[i + 1] - nums[i] <= ans){
                count++;
                i++;
            }
        }

        return count >= p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int s = 0, e = nums.back() - nums[0], m, ans;

        while (s <= e){
            m = s + (e - s) / 2; 

            if (check(nums, p, m)){
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