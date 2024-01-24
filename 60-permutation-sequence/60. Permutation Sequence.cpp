class Solution {
public:
    long long fact(int n){
        long long f = 1;
        for (int i = 1; i <= n; i++) f *= i;

        return f;
    }

    void kthPermutation(string &s, int k, string &str){
        if (s.size() == 0) return;
        int n = s.size();
        int idx = (k - 1) / fact(n - 1);

        str.push_back(s[idx]);
        s.erase(s.begin() + idx);
        kthPermutation(s, (k - 1) % fact(n - 1) + 1, str);
    }

    string getPermutation(int n, int k) {
        string s, str;
        for (int i = 1; i <= n; i++){
            s.push_back('0' + i);
        }

        kthPermutation(s, k, str);

        return str;
    }
};