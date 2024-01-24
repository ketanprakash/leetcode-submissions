class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> nums;
        for (int i = 0; i < n; i++){
            nums.push_back({capital[i], profits[i]});
        }
        sort(nums.begin(), nums.end());
        priority_queue<int> q;

        int count = 0, i = 0;
        while (i < n && count < k){
            while (i < n && w >= nums[i].first){
                q.push(nums[i++].second);
            }
            if (q.empty()) return w;
            if (!q.empty() && count < k){
                w += q.top();
                q.pop();
                count++;
            }
        }

        while (!q.empty() && count < k){
            w += q.top();
            q.pop();
            count++;
        }

        return w;
    }
};