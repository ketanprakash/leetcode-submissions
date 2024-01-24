class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        unordered_map<int, vector<int>> prefix;
        prefix[0].push_back(-1);
        int curr = 0; 
        int ans = -1;
        int target = sum - x;

        if (target == 0) return nums.size();
        
        for (int i = 0; i < nums.size(); i++){
            curr += nums[i];

            if (prefix.count(curr - target)){
                for (int &y : prefix[curr - target]){
                    ans = ans == -1 ? n - i + y : min(ans, n - i + y);
                }
            }
            prefix[curr].push_back(i);
        }

        return ans;
    }
};