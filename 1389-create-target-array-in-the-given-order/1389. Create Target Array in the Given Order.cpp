class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> v(nums.size());

        for (int i = 0; i < index.size(); i++){
            for (int j = i + 1; j < index.size(); j++){
                if (index[i] >= index[j]) index[i]++;
            }
        }

        for (int i = 0; i < index.size(); i++){
            v[index[i]] = nums[i];
        }

        return v;
    }
};