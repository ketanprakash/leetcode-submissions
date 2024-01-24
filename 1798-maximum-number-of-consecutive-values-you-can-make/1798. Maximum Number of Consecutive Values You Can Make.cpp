class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        int reach = 0; 
        sort(coins.begin(), coins.end());
        for (int i = 0; i < coins.size(); i++){
            if (reach + 1 < coins[i]){
                return reach + 1;
            }
            else reach += coins[i];
        }

        return reach + 1;
    }
};