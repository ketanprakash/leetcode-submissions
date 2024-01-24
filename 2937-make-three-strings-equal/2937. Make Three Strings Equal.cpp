class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size(), n = 0; 
        
        for (int i = 0; i < min({n1, n2, n3}); i++){
            if (s1[i] == s2[i] && s1[i] == s3[i]) n++; 
            else break;
        }
        
        if (n == 0) return -1;
        return (n1 - n) + (n2 - n) + (n3 - n);
    }
};