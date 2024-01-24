class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(); 
        int s = 0, e = n - 1; 
        int leftMax = INT_MIN, rightMax = INT_MIN;
        int ans = 0; 
        while (s <= e){
            leftMax = max(leftMax, height[s]);
            rightMax = max(rightMax, height[e]);

            ans += leftMax < rightMax ? (leftMax - height[s++]) : (rightMax - height[e--]);
        }

        return ans;
    }
};