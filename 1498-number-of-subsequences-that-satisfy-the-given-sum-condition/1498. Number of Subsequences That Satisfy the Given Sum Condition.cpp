#define mod (int)(1e9 + 7)
class Solution {
public:
long long binaryExp(long long base,long long n){
        long long ans=1;
        while(n!=0){
            if(n%2==1){
                ans=(ans*base)%mod;
                n--;
            }else{
                base=(base*base)%mod;
                n=n/2;
            }
        }
        return ans;
    }
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int s = 0, e = nums.size() - 1; 

        int count = 0;
        while (s <= e){
            if (nums[s] + nums[e] <= target){
                count = (count % mod + binaryExp(2, e - s) % mod) % mod; 
                s++;
            }
            else {
                e--;
            }
        }

        return count;
    }
};