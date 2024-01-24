class Solution {
public:
    int mod = 1e9 + 7;
    int countHomogenous(string s) {
        long long total = 0, count = 0, subsCount = 0; 

        for (int i = 0; i < s.size(); i++){
            count++;
            if (i == s.size() - 1 || s[i + 1] != s[i]){
                if (count % 2 == 0) subsCount = (((count / 2) % mod) * ((count + 1) % mod)) % mod;
                else subsCount = ((((count + 1) / 2) % mod) * (count % mod)) % mod;

                total = (total % mod + subsCount % mod) % mod;
                count = 0;
            }
        }

        return total;
    }
};