class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<pair<int, int>> nums1;
        for (int i = 0; i < nums.size(); i++){
            nums1.push_back({nums[i], i});
        }

        sort(nums1.begin(), nums1.end());

        for (int i = 0; i < nums1.size(); i++){
            if (i - 1 >= 0 && nums1[i - 1].first == nums1[i].first){
                nums[nums1[i].second] = nums[nums1[i - 1].second];
            }
            else nums[nums1[i].second] = i;
        }

        return nums;
    }
};