class Solution {
public:
    int jump(vector<int>& nums) {
        int count = 0;

        int s = 0, e = 0;
        int last;
        while (e < nums.size() - 1){
            last = 0;
            for (int i = s; i <= e; i++){
                last = max(last, i + nums[i]);
            }
            s = e + 1;
            e = last;
            count++;
        }
        

        return count;
    }
};