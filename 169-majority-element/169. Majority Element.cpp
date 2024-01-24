class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element = nums[0];
        int cnt = 1, i;

        for (i = 1; i < nums.size(); i++){
            if (element == nums[i]){
                cnt++;
            }
            else cnt--;

            if (cnt == 0){
                element = nums[i];
                cnt = 1;
            }
        }

        return element;
    }
};