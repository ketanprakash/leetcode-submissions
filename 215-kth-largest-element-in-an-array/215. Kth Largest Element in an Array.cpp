class Solution {
public:
    
    int partition(vector<int> &nums, int low, int high) {
        int item = nums[low];
        int index = low;
        while(low < high) {
            while(low < nums.size() && nums[low] >= item) low++;
            while(nums[high] < item) high--;
            if(low < high)
                swap(nums[low], nums[high]);
        }
        swap(nums[high], nums[index]);
        return high;
    }
    
    int QuickSelect(vector<int> &nums, int low, int high, int k) {
        int r = rand() % (high - low + 1);
        swap(nums[low], nums[low + r]);
        int j = partition(nums, low, high);
        if(k == j)
            return nums[j]; 
        else if(k > j)
            return QuickSelect(nums, j + 1, high, k);
        else
            return QuickSelect(nums, 0, j - 1, k);
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        return QuickSelect(nums, 0, nums.size() - 1, k - 1);
    }
};