class Solution {
public:
    bool makesquare(vector<int> &matchsticks, int idx, int &a, int &b, int &c, int &d){
        if (idx == matchsticks.size()){
            if (a == 0 && b == 0 && c == 0 && d == 0){
                return true;
            }
        }

        if (a >= matchsticks[idx]){
            a -= matchsticks[idx];
            if (makesquare(matchsticks, idx + 1, a, b, c, d)) return true;
            a += matchsticks[idx];
        }

        if (b >= matchsticks[idx]){
            b -= matchsticks[idx];
            if (makesquare(matchsticks, idx + 1, a, b, c, d)) return true;
            b += matchsticks[idx];
        }

        if (c >= matchsticks[idx]){
            c -= matchsticks[idx];
            if (makesquare(matchsticks, idx + 1, a, b, c, d)) return true;
            c += matchsticks[idx];
        }

        if (d >= matchsticks[idx]){
            d -= matchsticks[idx];
            if (makesquare(matchsticks, idx + 1, a, b, c, d)) return true;
            d += matchsticks[idx];
        }

        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4 != 0) return false;
        sum /= 4;

        int a = sum, b = sum, c = sum, d = sum;
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        return makesquare(matchsticks, 0, a, b, c, d);
    }
};