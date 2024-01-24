class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i;
        for (i = 0; i < flowerbed.size(); i++){
            if (n == 0) break;
            if (flowerbed[i] == 1) continue; 
            if ((i - 1 < 0 || flowerbed[i - 1] == 0) && (i + 1 >= flowerbed.size() || flowerbed[i + 1] == 0)){
                flowerbed[i] = 1;
                n--;
            }
        }

        return n == 0;
    }
};