class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        
        for (int i = 0; i < nums.size(); i++){
            if (i - 1 >= 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < nums.size(); j++){
                if (j - 1 >= i + 1 && nums[j] == nums[j - 1]) continue;

                int s = j + 1, e = nums.size() - 1; 

                while (s < e){
                    if (s - 1 >= j + 1 && nums[s] == nums[s - 1]){
                        s++; 
                        continue;
                    }

                    if (e + 1 <= nums.size() - 1 && nums[e] == nums[e + 1]){
                        e--;
                        continue;
                    }

                    if ((long long)nums[s] + nums[e] == (long long)target - nums[i] - nums[j]){
                        ans.push_back({nums[i], nums[j], nums[s], nums[e]});
                        s++; e--;
                    }
                    else if ((long long)nums[s] + nums[e] < (long long)target - nums[i] - nums[j]){
                        s++;
                    }
                    else e--;
                }
            }
        }

        return ans;
    }
};