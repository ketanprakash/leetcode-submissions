class Solution {
public:
    bool check(vector<long long> &prefix, long long size, long long k){
        long long s = 0, e = size - 1, m, num, operations; 

        while (e < prefix.size()){
            m = (s + e) / 2;
            num = prefix[m] - (m - 1 >= 0 ? prefix[m - 1] : 0);
            operations = 0;
            operations += ((m - s) * num - ((m - 1 >= 0 ? prefix[m - 1] : 0) - (s - 1 >= 0 ? prefix[s - 1] : 0)));
            operations += (prefix[e] - prefix[m]) - num * (e - m);

            if (operations <= k) return true;
            s++;
            e++;
        }

        return false;
    }

    int maxFrequencyScore(vector<int>& nums, long long k) {
        sort(nums.begin(), nums.end());

        int s = 1, e = nums.size(), m;
        int ans = 0; 
        vector<long long> prefix(nums.size());
        prefix[0] = nums[0];

        for (int i = 1; i < nums.size(); i++){
            prefix[i] = nums[i] + prefix[i - 1];
        }

        while (s <= e){
            m = (s + e) / 2; 

            if (check(prefix, m, k)){
                ans = m; 
                s = m + 1;
            }
            else {
                e = m - 1;
            }
        }

        return ans;
    }
};