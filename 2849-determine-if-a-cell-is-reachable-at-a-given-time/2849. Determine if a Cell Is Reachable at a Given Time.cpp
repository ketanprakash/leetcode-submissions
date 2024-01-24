class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        return max(abs(sx - fx), abs(sy - fy)) > 0 ? t >= max(abs(sx - fx), abs(sy - fy)) : t != 1;
    }
};