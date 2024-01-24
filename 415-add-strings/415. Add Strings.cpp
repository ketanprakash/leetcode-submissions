class Solution {
public:
    string addStrings(string &num1, string &num2) {
        string str; 
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        int carry = 0, sum = 0;
        int i = 0; 

        for (; i < min(num1.size(), num2.size()); i++){
            sum = num1[i] - '0' + num2[i] - '0' + carry;
            carry = sum / 10; 
            sum = sum % 10; 
            str.push_back(sum + '0');
        }

        for (; i < num1.size(); i++){
            sum = num1[i] - '0' + carry; 
            carry = sum / 10; 
            sum = sum % 10;
            str.push_back(sum + '0');
        }

        for (; i < num2.size(); i++){
            sum = num2[i] - '0' + carry;
            carry = sum / 10; 
            sum = sum % 10;
            str.push_back(sum + '0');
        }

        if (carry != 0) str.push_back(carry + '0');

        reverse(str.begin(), str.end());

        return str;
    }
};