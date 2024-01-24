class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> q;

        int mx = INT_MIN;
        for (int i = 0; i < n; i++){
            while (nums[i] % 2 == 0) nums[i] /= 2;
            q.push(nums[i]);
            mx = max(nums[i], mx);
        }
        int ans = mx - q.top();
        while (q.top() % 2 != 0){
            int top = q.top() * 2; 
            q.pop();

            mx = max(top, mx);
            q.push(top);
            ans = min(ans, mx - q.top());
        }
        ans = min(ans, mx - q.top());

        return ans;
    }
};