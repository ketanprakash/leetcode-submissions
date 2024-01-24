class Solution {
public:
    int arrangeCoins(long long n) {
        if (n == 0) return 0;
        int s = 0, e = sqrt(2 * (long long)INT_MAX) + 1, m;
        int ans;

        while (s <= e){
            m = s + (e - s) / 2;
            if ((long long)m * (m + 1) / 2 <= n) {
                ans = m;
                s = m + 1;
            }
            else {
                e = m - 1;
            }
        }
        return ans;
    }
};