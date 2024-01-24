class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int ans = 0;
        long long reach = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++){
            while (reach + 1 < nums[i] && reach < n){
                reach += reach + 1; 
                ans++;
            }
            if (reach >= n) break;
            reach += nums[i];
        }

        while (reach < n){
            reach += reach + 1;
            ans++;
        }

        return ans;
    }
};