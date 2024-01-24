class Solution {
public:
    bool check(long long d1, long long d2, long long lcm, long long n1, long long n2, long long val){
        long long x = val - val / d1; 
        long long y = val - val / d2; 
        long long z = val - val / lcm;

        z = x + y - z;
        x -= z;
        y -= z;

        //x - not divisible by d1
        //y - not divisible by d2
        //z - not divisible by both

        if (n1 >= x) n1 -= x; 
        else n1 = 0;

        if (n2 >= y) n2 -= y; 
        else n2 = 0; 

        return z >= n1 + n2;
    }

    long long minimizeSet(long long d1, long long d2, long long n1, long long n2) {
        long long lcm = d1 / __gcd(d1, d2) * d2;

        long long s = 0, e = INT_MAX, ans = INT_MAX, m;

        while (s <= e){
            m = s + (e - s) / 2;
            if (check(d1, d2, lcm, n1, n2, m)){
                ans = m; 
                e = m - 1;
            }
            else {
                s = m + 1;
            }             
        }

        return ans;
    }
};