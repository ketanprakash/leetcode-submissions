class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int mn = INT_MAX, secondMn = INT_MAX;
        for (int i = 0; i < prices.size(); i++){
            if (prices[i] < mn){
                secondMn = mn;
                mn = prices[i];
            }
            else if (prices[i] < secondMn){
                secondMn = prices[i];
          }
        }
        
        if (secondMn + mn > money) return money;
        
        return money - secondMn - mn;
 }   

};