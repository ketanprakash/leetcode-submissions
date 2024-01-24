class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& nums) {
        vector<int> v(nums.size(), 1); 

        for (int i = 0; i < nums.size(); i++){
            for (int j = i - 1; j >= 0; j--){
                if (nums[j] <= nums[i]) v[i] = max(v[i], 1 + v[j]);
            }
        }

        return v;
    }
};