class Solution {
public:
    int getSum(int a, int b) {
        int ans = 0;
        int j = 1, carry = 0;
        for (int i = 0; i < 32; i++){
            carry = carry << 1;
            ans = ans | ((a & j) ^ (b & j) ^ (carry));
            carry = ((a & j) & (b & j)) | (carry & (a & j)) | (carry & (b & j));
            j = j << 1;
        }

        return ans;
    }
};