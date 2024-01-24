class Solution {
public:
    int atmost(vector<int> &nums, int k){
        int s = 0, e = 0, ans = 0, count = 0;
        unordered_map<int, int> m;

        while (e < nums.size()){
            if (m.find(nums[e]) == m.end() || m[nums[e]] == 0){
                count++;
            }
            m[nums[e]]++;

            while (count > k && s <= e){
                m[nums[s]]--;
                if (m[nums[s]] == 0) count--;
                s++;
            }

            ans += e - s + 1;
            e++;
        }
        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k - 1);
    }
};