class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        int carry = 1;
        for (int i = 0; i < digits.size(); i++){
            digits[i] = digits[i] + carry; 
            carry = digits[i] / 10; 
            digits[i] = digits[i] % 10;
        }
        if (carry != 0) digits.push_back(carry);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};