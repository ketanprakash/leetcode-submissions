class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int restSum = 0; 
        int sum = 0;
        for (int i = 0; i < n - k; i++){
            sum += cardPoints[i];
            restSum += cardPoints[i];
        }
        int minRestSum = restSum;

        for (int i = n - k; i < n; i++){
            sum += cardPoints[i];
            restSum += cardPoints[i];
            restSum -= cardPoints[i - n + k];
            minRestSum = min(restSum, minRestSum);
        }

        return sum - minRestSum;
    }
};