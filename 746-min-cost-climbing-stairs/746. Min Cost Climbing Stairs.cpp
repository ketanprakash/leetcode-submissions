class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size(); 

        int a = 0, b = cost[n - 1];

        int tmp;
        for (int i = n - 2; i >= 0; i--){
            tmp = b;
            b = cost[i] + min(a, b);
            a = tmp;
        }

        return min(a, b);
    }
};