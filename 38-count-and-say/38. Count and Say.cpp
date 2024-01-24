class Solution {
public:
    string countAndSay(int n) {
        
        string num = "1";

        int count; 

        string ans; 
        for (int i = 0; i < n - 1; i++){
            ans = "";
            count = 0;
            for (int i = 0; i < num.size(); i++){
                count++;
                if (i + 1 == num.size() || num[i] != num[i + 1]){
                    ans.push_back('0' + count);
                    ans.push_back(num[i]);
                    count = 0;
                }
            }

            num = ans;
        }

        return num;
    }
};