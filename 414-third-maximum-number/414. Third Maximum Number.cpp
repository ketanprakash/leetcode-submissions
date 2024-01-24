class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        long long first = LLONG_MIN, second = LLONG_MIN, third = LLONG_MIN;

        for (int i = 0; i < n; i++){
            if (first < (long long)nums[i]){
                third = second;
                second = first;
                first = nums[i];
            }
            else if (second < (long long)nums[i] && (long long)nums[i] != first){
                third = second; 
                second = nums[i];
            }
            else if (third < (long long)nums[i] && (long long)nums[i] != second && nums[i] != first){
                third = nums[i];
                cout << third << endl;
            }
        }
        if (third == LLONG_MIN) return first;
        return third;
    }
};