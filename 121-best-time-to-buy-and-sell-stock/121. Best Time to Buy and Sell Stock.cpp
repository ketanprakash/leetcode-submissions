class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lsf = prices[0], maxProfit = 0, i;
        for (i = 1; i < prices.size(); i++){
            maxProfit = maxProfit > prices[i] - lsf ? maxProfit : prices[i] - lsf;
            lsf = lsf < prices[i] ? lsf : prices[i];
        }

        return maxProfit;
    }
};