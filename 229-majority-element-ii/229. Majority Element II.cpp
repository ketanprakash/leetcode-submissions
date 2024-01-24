class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        long long element1 = LLONG_MAX, element2 = LLONG_MAX, cnt1 = 0, cnt2 = 0;
        int n = nums.size(), i;
        
        for (i = 0; i < n; i++){
            if (element1 == nums[i]) cnt1++;
            else if (element2 == nums[i]) cnt2++;
            else if (cnt1 == 0) {
                element1 = nums[i];
                cnt1 = 1;
            }
            else if (cnt2 == 0){
                element2 = nums[i];
                cnt2 = 1;
            }
            else {
                cnt1--; cnt2--;
            }
        }
        cnt1 = 0; cnt2 = 0;

        for (i = 0; i < n; i++) {
            if (nums[i] == element1) cnt1++;
            if (nums[i] == element2) cnt2++;
        }

        vector<int> ans; 
        if (cnt1 > n / 3) ans.push_back(element1);
        if (cnt2 > n / 3) ans.push_back(element2);

        return ans;
    }

};