class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); i++){
            int s = i + 1, e = nums.size() - 1; 
            if (i - 1 >= 0 && nums[i - 1] == nums[i]) continue;

            while (s < e){
                if (s - 1 >= i + 1 && nums[s] == nums[s - 1]){
                    s++; 
                    continue;
                }

                if (e + 1 <= nums.size() - 1 && nums[e] == nums[e + 1]) {
                    e--; 
                    continue;
                }

                if (nums[s] + nums[e] == -nums[i]){
                    ans.push_back({nums[i], nums[s], nums[e]});
                    s++; e--;
                }
                else if (nums[s] + nums[e] < -nums[i]){
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