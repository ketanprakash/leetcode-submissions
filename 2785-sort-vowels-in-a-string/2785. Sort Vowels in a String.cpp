class Solution {
public:
    string sortVowels(string s) {
        unordered_set<char> vowels; 
        vowels.insert('a'); vowels.insert('e'); vowels.insert('i'); vowels.insert('o'); vowels.insert('u'); vowels.insert('A'); vowels.insert('E'); vowels.insert('I'); vowels.insert('O'); vowels.insert('U');

        vector<char> str; 

        for (int i = 0; i < s.size(); i++){
            if (vowels.count(s[i])) {
                str.push_back(s[i]);
                s[i] = '1';
            }
        }

        sort(str.begin(), str.end(), greater<char>());
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '1'){
                s[i] = str.back(); 
                str.pop_back();
            }
        }

        return s;
    }
};