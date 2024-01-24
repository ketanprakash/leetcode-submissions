class Solution {
public:
    long long ans = 0;
    
    void merge(string &str, int s, int m, int e){
        string v1; 
        string v2; 
        
        for (int i = s; i <= m; i++) v1.push_back(str[i]);
        for (int i = m + 1; i <= e; i++) v2.push_back(str[i]);
        
        int i = 0, j = 0, k = s; 
        
        while (i < v1.size() && j < v2.size()){
            if (v1[i] <= v2[j]){
                str[k++] = v1[i++];
            }
            else {
                str[k++] = v2[j++];
                ans += v1.size() - i;
            }
        }
        
        while (i < v1.size()){
            str[k++] = v1[i++];
        }
        while (j < v2.size()){
            str[k++] = v2[j++];
        }
    }
    
    void mergeSort(string &str, int s, int e){
        if (s >= e) return;
        int m = s + (e - s) / 2;
        
        mergeSort(str, s, m);
        mergeSort(str, m + 1, e);
        merge(str, s, m, e);
    }
        
    long long minimumSteps(string &str) {
        mergeSort(str, 0, str.size() - 1);
        return ans;
    }
};