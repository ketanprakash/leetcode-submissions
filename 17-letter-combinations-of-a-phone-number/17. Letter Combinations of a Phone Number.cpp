class Solution {
public:
    void letterCombinations(string &digits, int idx, string &curr, vector<string> &ans, unordered_map<char, vector<char>> &letters){
        if (idx == digits.size()){
            ans.push_back(curr);
            return;
        }

        for (char letter : letters[digits[idx]]){
            curr.push_back(letter);
            letterCombinations(digits, idx + 1, curr, ans, letters);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        unordered_map<char, vector<char>> letters; 
        letters['2'] = {'a', 'b', 'c'};
        letters['3'] = {'d', 'e', 'f'};
        letters['4'] = {'g', 'h', 'i'};
        letters['5'] = {'j', 'k', 'l'};
        letters['6'] = {'m', 'n', 'o'};
        letters['7'] = {'p', 'q', 'r', 's'};
        letters['8'] = {'t', 'u', 'v'};
        letters['9'] = {'w', 'x', 'y', 'z'};
        string curr;
        vector<string> ans;
        letterCombinations(digits, 0, curr, ans, letters);

        return ans;
    }
};