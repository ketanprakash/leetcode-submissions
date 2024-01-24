#define mod 1000000007

class Solution {
public:
    long long maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<long long, long long>> nums;

        for (int i = 0; i < n; i++) {
            nums.push_back({efficiency[i], speed[i]});
        }

        sort(nums.begin(), nums.end(), greater<pair<long long, long long>>());
        priority_queue<long long, vector<long long>, greater<long long>> q;

        long long curr = 0, ans = 0, ans1 = 0;

        for (int i = 0; i < n; i++) {
            if (q.size() == k) {
                curr -= q.top();
                q.pop();
            }

            q.push(nums[i].second);
            curr += nums[i].second;
            ans = max(ans, curr * nums[i].first);
        }

        return ans % mod;
    }
};