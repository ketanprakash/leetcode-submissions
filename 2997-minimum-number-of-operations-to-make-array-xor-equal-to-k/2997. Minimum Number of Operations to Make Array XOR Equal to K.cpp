class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        for (int i = 0; i < nums.size(); i++){
            k ^= nums[i];
        }
        int count = 0;
        while (k){
            k &= k - 1;
            count++;
        }
        
        return count;
    }
};