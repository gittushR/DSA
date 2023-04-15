class Solution {
public:
    vector<vector<int>>memo;
    int dp(vector<vector<int>>& piles, int k,int i){
        if(i==piles.size())
        return 0;
        if(k==0)
        return 0;
        if(memo[k][i]!=-1)
        return memo[k][i];
        int sum=dp(piles,k,i+1);
        int val=0;
        for(int j=0;j<piles[i].size() && j<k;j++)
        {
            
            val+=piles[i][j];
            sum=max(sum,val+dp(piles,k-j-1,i+1));

        }
    return memo[k][i]=sum;
        
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
    memo.resize(2001, vector<int>(1001,-1));
    return dp(piles,k,0);
        
    }
};