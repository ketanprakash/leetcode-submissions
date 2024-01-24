class Solution {
public:
    long long merge(vector<int> &nums, int s, int m, int e){
        long long count = 0;
        int n1 = m - s + 1;
        int n2 = e - m;
        int n = n1 + n2;

        long long tmp1[n1], tmp2[n2];
        for (int i = 0; i < n1; i++){
            tmp1[i] = nums[i + s];
        }

        for (int i = 0; i < n2; i++){
            tmp2[i] = nums[i + m + 1];
        }

        int i = 0, j = 0, k = 0;

        while (i < n1 && j < n2){
            if (tmp1[i] <= 2 * tmp2[j]){
                i++;
            }
            else {
                j++;
                count += n1 - i;
            }
        }

        i = 0, j = 0, k = 0;
        while (i < n1 && j < n2){
            if (tmp1[i] <= tmp2[j]){
                nums[k++ + s] = tmp1[i++];
            }
            else {
                nums[k++ + s] = tmp2[j++];
            }
        }

        while (i < n1){
            nums[k++ + s] = tmp1[i++];
        }

        while (j < n2){
            nums[k++ + s] = tmp2[j++];
        }

        return count;
    }

    long long mergeSort(vector<int> &nums, int s, int e){
        if (s >= e) return 0;
        long long count = 0;
        int m = s + (e - s) / 2;
        count += mergeSort(nums, s, m);
        count += mergeSort(nums, m + 1, e);
        count += merge(nums, s, m, e);
        return count;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};