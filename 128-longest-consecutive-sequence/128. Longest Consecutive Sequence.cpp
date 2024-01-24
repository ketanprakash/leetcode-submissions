class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s; 

        for (int i = 0; i < nums.size(); i++){
            s.insert(nums[i]);
        }
        
        int count = 0, maxCount = 0, x;
        for (int i = 0; i < nums.size(); i++){
            if (s.count(nums[i]) == 0) continue;

            count = 0; 
            x = nums[i];

            while (s.count(x) != 0){
                count++;
                s.erase(x);
                x--;
            }

            x = nums[i] + 1;
            while (s.count(x) != 0){
                count++;
                s.erase(x);
                x++;
            }

            maxCount = max(count, maxCount);
        }

        return maxCount;
    }
};