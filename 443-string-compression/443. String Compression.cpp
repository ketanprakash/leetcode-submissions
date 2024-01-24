class Solution {
public:
    int helper(vector<char> &chars, int i, int j, int count){
        if (i == chars.size()){
            return j;
        }

        count++;
        if (i == chars.size() - 1 || chars[i + 1] != chars[i]){
            chars[j++] = chars[i];
            if (count > 1){
                string c = to_string(count);
                for (char &ch : c) chars[j++] = ch;
            }
            return helper(chars, i + 1, j, 0);
        }
        
        return helper(chars, i + 1, j, count);
    }

    int compress(vector<char>& chars) {
        return helper(chars, 0, 0, 0);
    }
};