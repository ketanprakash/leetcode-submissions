class Solution {
public:
    int countOdds(int low, int high) {
        if (!(low & 1)) low++; 
        if (!(high & 1)) high--;

        return max((high - low) / 2 + 1, 0);
    }
};