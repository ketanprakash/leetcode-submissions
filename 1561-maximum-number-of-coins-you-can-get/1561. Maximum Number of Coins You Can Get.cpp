class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size() / 3;
        sort(piles.begin(), piles.end());
        int ans = 0;
        for (int i = n; i < 3 * n; i += 2){
            ans += piles[i];
        }

        return ans;
    }
};