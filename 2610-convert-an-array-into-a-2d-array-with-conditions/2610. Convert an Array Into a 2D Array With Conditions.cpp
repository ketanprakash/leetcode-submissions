class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> v;
        
        int count = 0;
        
        for (int i = 0; i < nums.size(); i++){
            count++;
            if (i == n - 1 || nums[i + 1] != nums[i]){
                for (int j = 0; j < count; j++){
                    if (j == v.size()) v.push_back({});
                    v[j].push_back(nums[i]);
                }
                count = 0;

            }
                
        }
        
        return v;

    }
};