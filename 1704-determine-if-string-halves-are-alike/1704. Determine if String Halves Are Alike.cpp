class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<char> v;
        
        v.insert('a');
        v.insert('e');
        v.insert('i');
        v.insert('o');
        v.insert('u');
        int vowels = 0;
        for (int i = 0; i < s.size() / 2; i++){
            if (v.count(s[i]) || v.count(s[i] - 'A' + 'a')) vowels++;
        }


        for (int i = s.size() / 2; i < s.size(); i++){
            if (v.count(s[i]) || v.count(s[i] - 'A' + 'a')) vowels--;
        }
        
        return vowels == 0;
    }
};