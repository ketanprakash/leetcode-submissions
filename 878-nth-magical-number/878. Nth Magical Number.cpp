class Solution {
public:
    long long mod = 1e9 + 7;
    int nthMagicalNumber(int n, int a, int b) {
        long long lcm = ((long long)a / __gcd(a, b)) * b;

        long long s, e, m, ans, x, countBefore;
        
        s = 1, e = n;

        while (s <= e){
            m = s + (e - s) / 2;

            x = m * a;
            countBefore = 0;
            countBefore += x % a == 0 ? x / a - 1 : x / a;
            countBefore += x % b == 0 ? x / b - 1 : x / b;
            countBefore -= x % lcm == 0 ? x / lcm - 1 : x / lcm;

            if (countBefore + 1 == n) return x % mod;
            else if (countBefore + 1 < n){
                s = m + 1;
            }
            else {
                e = m - 1;
            }
        }

        s = 1, e = n;
        while (s <= e){
            m = s + (e - s) / 2;

            x = m * b;
            countBefore = 0;
            countBefore += x % a == 0 ? x / a - 1 : x / a;
            countBefore += x % b == 0 ? x / b - 1 : x / b;
            countBefore -= x % lcm == 0 ? x / lcm - 1 : x / lcm;

            if (countBefore + 1 == n) return x % mod;
            else if (countBefore + 1 < n){
                s = m + 1;
            }
            else {
                e = m - 1;
            }
        }

        return -1;
    }
};