class Solution {
public:
    string removeKdigits(string &num, int k) {
        if (num.size() == k) return "0";

        string str; 

        for (int i = 0; i < num.size(); i++){
            while (!str.empty() && str.back() > num[i] && k > 0){
                str.pop_back();
                k--;
            }
            str.push_back(num[i]);
        }

        int i = 0; 

        while (k--) str.pop_back();
        
        while (i < str.size() - 1 && str[i] == '0'){
            i++;
        }

        return str.substr(i);
    }
};