class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> v; 
        int n = nums.size() - 1, m;
        while (n >= 0 && nums[n] >= 0){
            v.push_back(nums[n]);
            n--;
        }
        n++;
        m = v.size();

        for (int i = 0; i < n; i++){
            nums[i] = nums[i] * nums[i];
        }
        for (int i = 0; i < m; i++){
            v[i] = v[i] * v[i];
        }

        reverse(nums.begin(), nums.begin() + n);
        reverse(v.begin(), v.end());

        int i = n - 1, j = m - 1, k = n + m - 1; 

        while (i >= 0 && j >= 0){
            if (nums[i] > v[j]){
                nums[k--] = nums[i--];
            }
            else {
                nums[k--] = v[j--];
            }
        }

        while (j >= 0){
            nums[k--] = v[j--];
        }

        return nums;
    }
};