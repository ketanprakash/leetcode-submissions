class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        long long ans = 0;

        vector<pair<int, int>> nums; 

        for (int i = 0; i < nums1.size(); i++){
            nums.push_back({nums2[i], nums1[i]});
        }
        sort(nums.begin(), nums.end(), greater<pair<int, int>>());
        priority_queue<int, vector<int>, greater<int>> q;
        long long curr = 0;
        for (int i = 0; i < k; i++){
            curr += nums[i].second;
            q.push(nums[i].second);
        }
        ans = (long long)nums[k - 1].first * curr;

        for (int i = k; i < nums.size(); i++){
            curr -= q.top();
            q.pop(); 
            curr += nums[i].second;
            q.push(nums[i].second);

            ans = max(ans, (long long)nums[i].first * curr);
        }

        return ans;
    }
};