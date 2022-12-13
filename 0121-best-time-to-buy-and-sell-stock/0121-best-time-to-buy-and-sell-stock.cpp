class Solution {
public:
    int maxProfit(vector<int>& prices) {
         int least=INT_MAX, currprofit=0,op=INT_MIN;
        for(int i=0;i<prices.size();i++){
            least=min(least,prices[i]);
            currprofit=prices[i]-least;
            op=max(op,currprofit);
        }
        return op;
    }
};