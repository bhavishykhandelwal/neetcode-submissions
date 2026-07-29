class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=0;
        int buyPrice=prices[0];
        for(int i=0;i<prices.size();i++){
            if(prices[i]<buyPrice){
                buyPrice=prices[i];
            }
            maxProfit=max(maxProfit,prices[i]-buyPrice);
        }
        return maxProfit;
    }
};
