class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int totalSum = 0;
        for (int i = 0; i < n; i++) {
            totalSum += cardPoints[i];
        }
        
        if (k == n) {
            return totalSum;
        }
        int windowSum = 0;
        for (int i = 0; i < n - k; i++) {
            windowSum += cardPoints[i];
        }
        
        int minWindowSum = windowSum;
        for (int i = n - k; i < n; i++) {
            windowSum += cardPoints[i] - cardPoints[i - (n - k)];
            minWindowSum = min(minWindowSum, windowSum);
        }
        return totalSum - minWindowSum;
    }
};
