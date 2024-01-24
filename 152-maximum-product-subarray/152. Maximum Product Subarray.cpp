class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0], minProd = nums[0], ans = nums[0], tmp; 

        for (int i = 1; i < nums.size(); i++){
            tmp = maxProd;
            maxProd = max({maxProd * nums[i], minProd * nums[i], nums[i]});
            minProd = min({tmp * nums[i], minProd * nums[i], nums[i]});

            ans = max(maxProd, ans);
        }

        return ans;
    }
};