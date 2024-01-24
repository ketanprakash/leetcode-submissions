class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        vector<pair<int, int>> v; 
        for (int i = 0; i < nums.size(); i++){
            v.push_back({nums[i], i});
        }
        sort(v.begin(), v.end());

        for (int i = 1; i < nums.size(); i++){
            auto &[num1, idx1] = v[i - 1];
            auto &[num2, idx2] = v[i];

            if (num2 - num1 <= valueDiff && abs(idx1 - idx2) <= indexDiff) return true;
        }

        return false;
    }
};