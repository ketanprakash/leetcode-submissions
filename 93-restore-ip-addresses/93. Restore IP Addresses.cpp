class Solution {
public:
    bool check(string &ip){
        string str;
        for (int i = 0; i <= ip.size(); i++){
            if (ip[i] == '.' || i == ip.size()){
                if (str.size() == 0 || str.size() > 3) return false;
                int x = stoi(str);
                if (x < 0 || x > 255 || to_string(x) != str) return false;
                str.clear();
            }
            else {
                str.push_back(ip[i]);
            }
        }

        return true;
    }

    void restoreIpAddresses(string &s, int idx, string &curr, vector<string> &ans, int &count){
        if (idx == s.size()){
            if (count == 3 && check(curr)) ans.push_back(curr);
            return;
        }

        curr.push_back(s[idx]);
        if (count < 3 && idx < s.size() - 1){
            curr.push_back('.');
            count++;
            restoreIpAddresses(s, idx + 1, curr, ans, count);
            count--;
            curr.pop_back();
        }

        restoreIpAddresses(s, idx + 1, curr, ans, count);
        curr.pop_back();
    }

    vector<string> restoreIpAddresses(string &s) {
        string curr;
        vector<string> ans;
        int count = 0;
        restoreIpAddresses(s, 0, curr, ans, count);

        return ans;
    }
};