class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size(); 
        k++; 
        if (k > n) k = n; 

        int i = 0, j; 
        unordered_map<int, int> m;

        for (j = 0; j < k; j++){
            m[nums[j]]++;
        }
        if (m.size() < k) return true;

        while (j < n){
            m[nums[i]]--;
            if (m[nums[i]] == 0) m.erase(nums[i]);
            i++;
            m[nums[j]]++;
            j++;
            if (m.size() < k) return true;
        }

        return false;
    }
};