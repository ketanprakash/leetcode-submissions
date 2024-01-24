class Solution {
public:
    int strStr(string &haystack, string &needle) {
        bool found;
        int i, j;

        for (i = 0; i < haystack.size(); i++){
            if (haystack[i] == needle[0]){
                found = true;
                for (j = 0; j < needle.size(); j++){
                    if (haystack[j + i] != needle[j]){
                        found = false; 
                        break;
                    }
                }
                if (found) return i;
            }
        }

        return -1;
    }
};