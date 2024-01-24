class Solution {
public:
    bool isPerfectSquare(int num) {
        long long s = 0, e = num, m, ans;

        while (s <= e){
            m = s + (e - s) / 2;

            if (m * m <= num){
                ans = m; 
                s = m + 1;
            }
            else {
                e = m - 1;
            }
        }

        return ans * ans == num;
    }
};