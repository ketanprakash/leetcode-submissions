class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m; 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; 
        vector<int> v;

        for (int i = 0; i < nums.size(); i++){
            m[nums[i]]++;
        }

        for (auto p : m){
            if (q.size() == k){
                if (p.second < q.top().first) {
                    continue;
                }
                else q.pop();
            }
            q.push({p.second, p.first});
        }

        for (int i = 0; i < k; i++){
            v.push_back(q.top().second);
            q.pop();
        }

        return v;
    }
};