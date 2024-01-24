class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, count = 0, longestSum = 0, maxCount = 0; 
        for (int i = 0; i < n; i++){
            count++; 
            sum += nums[i];
            if (i == n - 1 || nums[i] + 1 != nums[i + 1]){
                if (count > maxCount){
                    maxCount = count;
                    longestSum = sum;
                }
                break;
            }
        }
        int x = longestSum;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n; i++){
            if (x == nums[i]) x++;
        }
        
        return x;
    }
};