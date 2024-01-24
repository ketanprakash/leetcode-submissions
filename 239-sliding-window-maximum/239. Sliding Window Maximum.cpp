class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q; 
        vector<int> v;
        for (int i = 0; i < k; i++){
            while (!q.empty() && q.back() < nums[i]){
                q.pop_back();
            }
            q.push_back(nums[i]);
        }
        v.push_back(q.front());
        for (int i = k; i < nums.size(); i++){
            if (nums[i - k] == q.front()){
                q.pop_front();
            }
            while (!q.empty() && q.back() < nums[i]){
                q.pop_back();
            }
            q.push_back(nums[i]);
            v.push_back(q.front());
        }
        return v;
    }
};