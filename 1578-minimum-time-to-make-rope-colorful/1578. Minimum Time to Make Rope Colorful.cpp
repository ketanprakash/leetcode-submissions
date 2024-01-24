class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int ans = 0;
        int count = 0;
        int sumCost = 0; 
        int maxCost = INT_MIN;

        for (int i = 0; i < n; i++){
            sumCost += neededTime[i];
            maxCost = max(maxCost, neededTime[i]);
            if (i == n - 1 || colors[i] != colors[i + 1]){
                ans += sumCost - maxCost;
                sumCost = 0;
                maxCost = INT_MIN;
            }
        }

        return ans;
    }
};