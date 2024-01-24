class Solution {
public:
    void add(string &str1, string &str2){
        if (str1.size() == 0) {
            str1 = str2; 
            str2 = "";
            return;
        }

        if (str2.size() == 0){
            return;
        }

        string str;
        reverse(str1.begin(), str1.end());
        reverse(str2.begin(), str2.end());
        
        int carry = 0;
        int i, x, y, sum;
        for (i = 0; i < min(str1.size(), str2.size()); i++){
            x = str1[i] - '0', y = str2[i] - '0';
            sum = x + y + carry;
            carry = sum / 10;
            sum = sum % 10;
            str.push_back(sum + '0');
        }

        for (; i < str1.size(); i++){
            x = str1[i] - '0';
            sum = x + carry;
            carry = sum / 10; 
            sum = sum % 10;
            str.push_back(sum + '0');
        }

        for (; i < str2.size(); i++){
            y = str2[i] - '0';
            sum = y + carry;
            carry = sum / 10; 
            sum = sum % 10; 
            str.push_back(sum + '0');
        }

        if (carry) str.push_back(carry + '0');
        reverse(str.begin(), str.end());
        str1 = str; str2 = "";
    }
    
    void multiply(string &str1, string &str, int divisor, int zeros){
        for (int i = 0; i < zeros; i++) str.push_back('0');
        reverse(str1.begin(), str1.end());
        int x, prod, carry = 0;
        for (int i = 0; i < str1.size(); i++){
            x = str1[i] - '0';
            prod = x * divisor + carry;
            carry = prod / 10;
            prod = prod % 10;
            str.push_back(prod + '0');
        }
        if (carry) str.push_back(carry + '0');
        reverse(str.begin(), str.end());
        reverse(str1.begin(), str1.end());
    }

    string multiply(string &num1, string &num2) {
        int divisor;
        reverse(num1.begin(), num1.end());
        string result, str;
        for (int i = 0; i < num1.size(); i++){
            divisor = num1[i] - '0';
            multiply(num2, str, divisor, i);
            add(result, str);
        }

        reverse(result.begin(), result.end());

        while (result.size() > 1 && result.back() == '0'){
            result.pop_back();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};