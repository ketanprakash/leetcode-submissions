class Solution {
public:
    bool findDifferentBinaryString(string &ans, int n, unordered_set<string> &nums){
        if (n == 0){
            if (nums.count(ans)) return false;

            return true;
        }

        ans.push_back('0');
        if (findDifferentBinaryString(ans, n - 1, nums)) return true;
        ans.pop_back();
        ans.push_back('1');
        if (findDifferentBinaryString(ans, n - 1, nums)) return true;
        ans.pop_back();

        return false;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> numsSet; 
        string ans;
        for (string &s : nums) numsSet.insert(s);

        findDifferentBinaryString(ans, nums.size(), numsSet);

        return ans;
    }
};