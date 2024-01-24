class Solution {
public:
    int findComplement(int num) {
        int n = num;
        int mask = 0;

        while (n){
            n = n >> 1;
            mask = (mask << 1) | 1;
        }

        return num ^ mask;
    }
};