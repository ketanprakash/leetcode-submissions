class Solution {
public:
    int atmost(vector<int> &nums, int k){
        int s = 0, e = 0;
        int ans = 0; 

        while (e < nums.size()){
            if (nums[e] % 2 != 0) k--;
            while (k < 0 && s <= e){
                if (nums[s] % 2 != 0) k++;
                s++;
            }
            ans += e - s + 1;
            e++;
        }
        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k - 1);
    }
};