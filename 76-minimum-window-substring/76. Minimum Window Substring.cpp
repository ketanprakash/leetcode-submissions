class Solution {
public:
    string minWindow(string str, string t) {
        int s = 0, e = 0, counter = t.size(), size = -1;
        unordered_map<char, int> m;
        int min_s = 0, min_e = 0;

        for (char ch : t) m[ch]++;

        while (e < str.size()){
            if (m[str[e]] > 0){
                counter--;
            }
            m[str[e]]--;
            while (counter == 0){
                if (size == -1 || size > e - s + 1){
                    size = e - s + 1;
                    min_s = s;
                    min_e = e;
                }
                if (m[str[s]] == 0){
                    counter++;
                }
                m[str[s]]++;
                s++; 
            }

            e++;
        }

        return size == -1 ? "" : str.substr(min_s, min_e - min_s + 1);
    }
};