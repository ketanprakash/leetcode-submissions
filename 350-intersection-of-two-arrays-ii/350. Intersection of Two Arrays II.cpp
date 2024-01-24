class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m; 
        for (int &x : nums1) m[x]++;
        vector<int> ans;
        for (int &x : nums2){
            if (m.count(x)){
                m[x]--;
                ans.push_back(x);
                if (m[x] == 0) m.erase(x);
            }
        }

        return ans;
    }
};