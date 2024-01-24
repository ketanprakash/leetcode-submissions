class Solution {
public:
    string largestGoodInteger(string num) {
        int ans = -1;

        for (int i = 2; i < num.size(); i++){
            if (num[i - 2] == num[i - 1] && num[i - 1] == num[i]){
                ans = max(ans, num[i] - '0');
            }
        }
        string a = to_string(ans);
        return ans == -1 ? "" : a + a + a;
    }
};