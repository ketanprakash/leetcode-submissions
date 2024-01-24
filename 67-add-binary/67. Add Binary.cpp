class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() < b.size()) swap(a, b);
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int i = 0; 
        int carry = 0;
        while (i < a.size()){
            a[i] = (a[i] - '0') + (i >= b.size() ? 0 : b[i] - '0') + carry;
            carry = a[i] / 2;
            a[i] = (a[i] % 2) + '0';
            i++;
        }
        if (carry != 0) a.push_back(carry + '0');
        reverse(a.begin(), a.end());
        
        return a;
    }
};