class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_map<int, int> freq1; 
        unordered_map<int, int> freq2; 
        
        for (int i = 0; i < n; i++){
            freq1[nums1[i]]++;
            freq2[nums2[i]]++;
        }
        
        int toRemove1 = n / 2; 
        int toRemove2 = n / 2;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        for (int i = 0; i < n; i++){
            if (toRemove1 > 0 && freq1[nums1[i]] > 1) {
                toRemove1--;
                freq1[nums1[i]]--;
                nums1[i] = -1;
                if (freq1[nums1[i]] == 0) freq1.erase(nums1[i]);
                
            }
        }
        
        for (int i = 0; i < n; i++){
            if (toRemove2 > 0 && freq2[nums2[i]] > 1){
                toRemove2--;
                freq2[nums2[i]]--;
                nums2[i] = -1;
                if (freq2[nums2[i]] == 0) freq2.erase(nums2[i]);
            }
        }
        
        for (int i = 0; i < n; i++){
            if (nums1[i] == -1) continue;
            if (toRemove1 > 0 && freq1[nums1[i]] + (freq2.count(nums1[i]) ? freq2[nums1[i]] : 0) > 1) {
                toRemove1--;
                freq1[nums1[i]]--;
                nums1[i] = -1;
                if (freq1[nums1[i]] == 0) freq1.erase(nums1[i]);
            }
        }
        for (int i = 0; i < n; i++){
            if (nums2[i] == -1) continue;
            if (toRemove2 > 0 && (freq1.count(nums2[i]) ? freq1[nums2[i]] : 0) + freq2[nums2[i]] > 1){
                toRemove2--;
                freq2[nums2[i]]--;
                if (freq2[nums2[i]] == 0) freq2.erase(nums2[i]);
            }
        }
        
        unordered_set<int> s;
        for (auto [x, f] : freq1){
            s.insert(x);
        }
        
        for (auto [x, f] : freq2){
            s.insert(x);
        }
        
        return s.size() - toRemove1 - toRemove2;
    }
};