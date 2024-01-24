class Solution {
public:
    int mod = 1e9 + 7;
    vector<long long> nextSmallerElement(vector<int> &nums){
        long long n = nums.size();
        vector<long long> nse(n, n);
        stack<long long> st; 
        
        for (long long i = 0; i < n; i++){
            while (!st.empty() && nums[i] < nums[st.top()]){
                nse[st.top()] = i;
                st.pop();
            }
            
            st.push(i);
        }
        
        return nse;
    }

    vector<long long> previousSmallerElement(vector<int> &nums){
        long long n = nums.size(); 
        stack<long long> st;
        vector<long long> pse(n, -1);

        for (long long i = n - 1; i >= 0; i--){
            while (!st.empty() && nums[i] < nums[st.top()]){
                pse[st.top()] = i;
                st.pop();
            }
            
            st.push(i);
        }

        return pse;
    }

    vector<long long> prefixSum(vector<int> &nums){
        long long n = nums.size();
        vector<long long> prefix(n);
        prefix[0] = nums[0];

        for (long long i = 1; i < n; i++){
            prefix[i] = prefix[i - 1] + nums[i];
        }

        return prefix;
    }

    long long maxSumMinProduct(vector<int>& nums) {
        long long n = nums.size();
        vector<long long> pse, nse, prefix; 
        pse = previousSmallerElement(nums);
        nse = nextSmallerElement(nums);
        prefix = prefixSum(nums);

        long long s, e;
        long long sum;
        long long ans = 0;
        for (long long i = 0; i < n; i++){
            s = pse[i] + 1;
            e = nse[i] - 1;

            sum = prefix[e] - prefix[s] + nums[s];

            ans = max(ans, (long long)sum * nums[i]);
        }

        return ans % mod;
    }
};