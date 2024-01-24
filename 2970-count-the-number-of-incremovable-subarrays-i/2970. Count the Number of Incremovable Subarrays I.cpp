class Solution {
public:
    bool check(vector<int> &nums, int s, int e){
        vector<int> v; 
        for (int i = 0; i < s; i++) v.push_back(nums[i]);
        for (int i = e + 1; i < nums.size(); i++) v.push_back(nums[i]);
        
        for (int i = 1; i < v.size(); i++){
            if (v[i] <= v[i - 1]) return false;
        }
        
        return true;
    }
    
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        long long count = 0;
        
        for (int size = 1; size <= n; size++){
            for (int s = 0; s <= n - 1; s++){
                int e = s + size - 1;
                if (e >= n) break;
                count += check(nums, s, e);
            }
        }
        
        return count;
    }
};