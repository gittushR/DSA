class Solution {
public:
    int maxProfit(vector<int>& prices) {
         int least=prices[0],maxProfit=0;
        for(int i=1;i<prices.size();i++){
            least=min(least,prices[i]);
            int currprofit=prices[i]-least;
            maxProfit=max(maxProfit,currprofit);
        }
        return maxProfit;
    }
};