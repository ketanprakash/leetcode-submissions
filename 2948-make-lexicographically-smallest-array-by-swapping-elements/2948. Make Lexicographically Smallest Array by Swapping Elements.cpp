class Solution {
public:
    int limit;
    
    void merge(vector<int> &nums, int s, int m, int e){
        vector<int> v1, v2;
        
        for (int i = s; i <= m; i++) v1.push_back(nums[i]);
        for (int i = m + 1; i <= e; i++) v2.push_back(nums[i]);
        
        int i = 0, j = 0, k = s; 
        
        while (i < m - s + 1 && j < e - m){
            if (v2[j] <= v1[i] && abs(v2[j] - v1[i]) <= limit){
                nums[k++] = v2[j++];
            }
            else {
                nums[k++] = v1[i++];
            }
        }
        
        while (i < m - s + 1){
            nums[k++] = v1[i++];
        }
        
        while (j < e - m){
            nums[k++] = v2[j++];
        }
    }
    
    void mergeSort(vector<int> &nums, int s, int e){
        if (s >= e) return;
        int m = s + (e - s) / 2;
        
        mergeSort(nums, s, m);
        mergeSort(nums, m + 1, e);
        merge(nums, s, m, e);
    }
    
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        this -> limit = limit;
        mergeSort(nums, 0, nums.size() - 1);
        
        return nums;
    }
};