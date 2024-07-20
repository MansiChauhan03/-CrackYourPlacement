SOLUTION 1{
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        int start = prices[0];
        int len = prices.size();
        for(int i = 1;i<len; i++){
            if(start < prices[i]){
                max += prices[i] - start;
            }
            start = prices[i];
        }
        return max;
    }
};


SOLUTION 2:
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] - prices[i - 1] > 0) {
                result += prices[i] - prices[i - 1];
            }
        }

        return result;
        
    }
};
