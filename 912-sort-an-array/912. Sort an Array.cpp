class Solution {
public:
    int partition(vector<int> &nums, int s, int e){
        srand(time(0));
        int pi = (double)rand() / RAND_MAX * (e - s + 1) + s;
        swap(nums[pi], nums[s]);
        int i = s + 1, j = e; 
        int pivot = nums[s];

        while (true){
            while (i <= e && nums[i] < pivot) i++; 
            while (j >= s + 1 && nums[j] >= pivot) j--;

            if (i >= j) {
                swap(nums[s], nums[j]);
                return j; 
            }
            swap(nums[i], nums[j]);
        }

        return j;
    }

    void quickSort(vector<int> &nums, int s, int e){
        if (s >= e) return;
        int pi = partition(nums, s, e);

        quickSort(nums, s, pi - 1);
        quickSort(nums, pi + 1, e);
    }

    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);

        return nums;
    }
};