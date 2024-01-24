class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        int right = -1, left = n; 

        vector<int> rightIdx(dominoes.size());

        for (int i = 0; i < dominoes.size(); i++){
            if (dominoes[i] == 'L'){
                right = -1;
            }
            else if (dominoes[i] == 'R'){
                right = i;
            }
            else {
                rightIdx[i] = right;
            }
        }

        for (int i = dominoes.size() - 1; i >= 0; i--){
            if (dominoes[i] == 'L'){
                left = i;
            }
            else if (dominoes[i] == 'R'){
                left = n;
            }
            else {
                if ((rightIdx[i] == -1 && left == n)){

                }
                else if (rightIdx[i] == -1){
                    dominoes[i] = 'L';
                }
                else if (left == n){
                    dominoes[i] = 'R';
                }
                else {
                    if ((abs(rightIdx[i] - i) == abs(left - i))){

                    }
                    else if (abs(i - rightIdx[i]) < abs(i - left)) dominoes[i] = 'R';
                    else dominoes[i] = 'L';
                }
            }
        }

        return dominoes;
    }
};