class Solution {
public:
    int minFlips(string s) {
        int n = s.size(); 
        s += s;
        int count0even = 0, count1even = 0, count0odd = 0, count1odd = 0;

        for (int i = 0; i < n; i++){
            if (i % 2 == 0){
                if (s[i] == '0') count0even++;
                else count1even++; 
            }
            else {
                if (s[i] == '0') count0odd++;
                else count1odd++;
            }
        }
        int ans = min(count1even + count0odd, count1odd + count0even);

        for (int i = n; i < s.size(); i++){
            if ((i - n) % 2 == 0){
                if (s[i - n] == '0') count0even--;
                else count1even--; 
            }
            else {
                if (s[i - n] == '0') count0odd--;
                else count1odd--;
            }

            if (i % 2 == 0){
                if (s[i] == '0') count0even++;
                else count1even++; 
            }
            else {
                if (s[i] == '0') count0odd++;
                else count1odd++;
            }
            ans = min({count1even + count0odd, count1odd + count0even, ans});
        }

        return ans;
    }
};