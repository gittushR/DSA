class Solution {
private:
    const int M = 1e9 + 7;
    int dp[101][101][101];
    int f(int i, int n, int mini, vector<int>& g, vector<int>& p, int use, int pro){
        pro = min(pro, mini);
        if(i>= g.size()){
            if(use <= n && pro >= mini) return 1;
            return 0;
        }
        if(use > n) return 0;
        if(dp[i][use][pro] != -1) return dp[i][use][pro];
        int pick = f(i + 1, n, mini, g, p, use + g[i], pro + p[i]);
        int not_pick = f(i + 1, n, mini, g, p, use, pro);
        return dp[i][use][pro] = (pick + not_pick)%M;
    }
public:
    int profitableSchemes(int n, int mini, vector<int>& g, vector<int>& p) {
        memset(dp, -1, sizeof(dp));
        return f(0, n, mini, g, p, 0, 0);
    }
};