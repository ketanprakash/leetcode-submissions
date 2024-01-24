class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end());
        long long toBeAdded = 0; 
        long long maxReachable = 0; 
        
        for (int i = 0; i < coins.size(); i++){
            while (maxReachable + 1 < coins[i]){
                toBeAdded++;
                maxReachable += maxReachable + 1;
            }
            maxReachable += coins[i];
        }
        
        while (maxReachable < target){
            toBeAdded++;
            maxReachable += maxReachable + 1;
        }
        
        return toBeAdded;
    }
};