class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        int count1 = 0, count2 = 0; 
        
        unordered_map<int, int> f;
        for (int &x : nums1) f[x]++;
        
        for (int &x : nums2){
            if (f.count(x)){
                count1 += f[x];
                f.erase(x);
            }
        }
        
        f = unordered_map<int, int>();
        for (int &x : nums2) f[x]++;
        
        for (int &x : nums1){
            if (f.count(x)){
                count2 += f[x];
                f.erase(x);
            }
        }
        
        return {count1, count2};
    }
};