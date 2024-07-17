class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curr_min=INT_MAX;
        int max=0;
        for(int i=0;i<prices.size();i++){
            int cp=prices[i];
            if(cp<curr_min){
                curr_min=cp;
            }
            else{
                int d=cp-curr_min;
                if(d>max){
                    max=d;
                }
            }
        }
        return max;
    }
};
