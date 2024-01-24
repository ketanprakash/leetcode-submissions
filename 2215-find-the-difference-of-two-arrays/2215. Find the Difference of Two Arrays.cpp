class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1, s2;

        for (int i = 0; i < nums1.size(); i++){
            s1.insert(nums1[i]);
        }

        for (int i = 0; i < nums2.size(); i++){
            s1.erase(nums2[i]);
            s2.insert(nums2[i]);
        }

        for (int i = 0; i < nums1.size(); i++){
            s2.erase(nums1[i]);
        }

        vector<vector<int>> ans(2);

        for (int i : s1) ans[0].push_back(i);
        for (int i : s2) ans[1].push_back(i);

        return ans;
    }
};