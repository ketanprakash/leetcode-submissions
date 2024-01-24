class Solution {
public:
    bool check(vector<int> &nums, int threshold, int divisor){
        int sum = 0;
        for (int i = 0; i < nums.size(); i++){
            sum += nums[i] % divisor == 0 ? nums[i] / divisor : nums[i] / divisor + 1;
        }

        return sum <= threshold;
    }

    int findMax(vector<int> &nums){
        int maxm = nums[0];

        for (int i = 0; i < nums.size(); i++){
            maxm = max(nums[i], maxm);
        }

        return maxm;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int s = 1, e = findMax(nums), m, ans = -1;

        while (s <= e){
            m = s + (e - s) / 2;;
            
            if (check(nums, threshold, m)){
                ans = m;
                e = m - 1;
            }
            else {
                s = m + 1;
            }
        }

        return ans;
    }
};