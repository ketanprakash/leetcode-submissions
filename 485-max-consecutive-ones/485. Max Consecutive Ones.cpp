class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size(); 
        int s = 0, e = -1; 
        int k = 0; 

        while (e + 1 < n){
            e++;
            if (nums[e] == 0){
                k--;
            }
            if (k < 0) {
                if (nums[s] == 0) k++;
                s++; 
            }
        }

        return e - s + 1;
    }
};