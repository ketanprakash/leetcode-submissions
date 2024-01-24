bool f(string &a, string &b){
    return (a + b) > (b + a);
}

class Solution {
public:

    string largestNumber(vector<int>& nums) {
        vector<string> strings(nums.size());

        for (int i = 0; i < nums.size(); i++){
            strings[i] = to_string(nums[i]);
        }

        sort(strings.begin(), strings.end(), f);
        string ans; 

        for (int i = 0; i < strings.size(); i++){
            ans.insert(ans.end(), strings[i].begin(), strings[i].end());
        }

        int i = 0;
        while (i < ans.size() - 1 && ans[i] == '0') i++;

        ans = ans.substr(i);

        return ans;
    }
};