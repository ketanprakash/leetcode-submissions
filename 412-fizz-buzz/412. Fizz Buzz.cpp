class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        string str; 

        for (int i = 1; i <= n; i++){
            str.clear();
            if (i % 3 == 0) str += "Fizz";
            if (i % 5 == 0) str += "Buzz";

            if (str.size() == 0) str += to_string(i);
            ans.push_back(str);
        }

        return ans;
    }
};