class Solution {
public:
    int mod = 1e9 + 7;
    
    int maximumXorProduct(long long a, long long b, int n) {
        long long ai, bi;
        long long axorx = a, bxorx = b;
        for (int i = n - 1; i >= 0; i--){
            ai = (a >> i) & 1LL;
            bi = (b >> i) & 1LL;
            
            if (ai == bi){
                axorx = axorx | (1LL << i);
                bxorx = bxorx | (1LL << i);
            }
            else {
                if (axorx > bxorx){
                    bxorx = bxorx | (1LL << i);
                    axorx = axorx & ~(1LL << i);
                }
                else {
                    axorx = axorx | (1LL << i);
                    bxorx = bxorx & ~(1LL << i);
                }
            }
        }
        return ((axorx % mod) * (bxorx % mod)) % mod;
    }
};