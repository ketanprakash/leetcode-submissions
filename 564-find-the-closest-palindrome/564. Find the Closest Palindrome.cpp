class Solution {
public:
    string convert(string root, bool even){
        string str = root;

        if (even){
            reverse(root.begin(), root.end());
            str += root;
        }
        else {
            root.pop_back();
            reverse(root.begin(), root.end());
            str += root;
        }

        return str;
    }

    string nearestPalindromic(string n) {
        int num = n.size(); 
        bool even = num % 2 == 0 ? true : false;

        string palinRoot = n.substr(0, (num + 1) / 2);
        string palinRootPrev = to_string(stoll(palinRoot) - 1);
        string palinRootNext = to_string(stoll(palinRoot) + 1);

        int m = palinRoot.size(); 
        palinRoot = convert(palinRoot, even);

        if (palinRootPrev == "0" && even) palinRootPrev = "9";
        else if (palinRootPrev.size() < m){
            palinRootPrev = "";
            for (int i = 0; i < palinRoot.size() - 1; i++){
                palinRootPrev.push_back('9');
            }
        }
        else palinRootPrev = convert(palinRootPrev, even);

        if (palinRootNext.size() > m){
            palinRootNext = "";
            palinRootNext.push_back('1');
            for (int i = 0; i < palinRoot.size() - 1; i++) palinRootNext.push_back('0');
            palinRootNext.push_back('1');
        }
        else palinRootNext = convert(palinRootNext, even);

        string ans;
        long long diff = LLONG_MAX;

        if (abs(stoll(palinRootPrev) - stoll(n)) < diff){
            diff = abs(stoll(palinRootPrev) - stoll(n));
            ans = palinRootPrev;
        }

        if (palinRoot != n){
            if (abs(stoll(palinRoot) - stoll(n)) < diff){
                diff = abs(stoll(palinRoot) - stoll(n));
                ans = palinRoot;
            }
        }

        if (abs(stoll(palinRootNext) - stoll(n)) < diff){
            diff = abs(stoll(palinRootNext) - stoll(n));
            ans = palinRootNext;
        }

        return ans;
    }
};