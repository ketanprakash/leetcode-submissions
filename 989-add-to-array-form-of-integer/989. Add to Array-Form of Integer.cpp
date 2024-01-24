class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        reverse(num.begin(), num.end());
        int carry = 0;
        int i = 0;

        while (k && i < num.size()){
            num[i] = num[i] + (k % 10) + carry;
            carry = num[i] / 10;
            num[i] = num[i] % 10;

            i++; 
            k = k / 10;
        }
        
        while (i < num.size()){
            num[i] = num[i] + carry; 
            carry = num[i] / 10;
            num[i] = num[i] % 10;

            i++;
        }

        while (k){
            num.push_back(k % 10 + carry);
            carry = num.back() / 10;
            num.back() = num.back() % 10;

            k = k / 10;
        }


        if (carry != 0) num.push_back(carry);
        
        reverse(num.begin(), num.end());

        return num;
    }
};