class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int t) {
        vector<vector<int>> cost(n,vector<int>(n,1e9));
        for(auto it: edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            cost[u][v]=wt;
            cost[v][u]=wt;
        }
        for(int i=0;i<n;i++)cost[i][i]=0;
        
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(cost[i][k]==1e9 or cost[k][j]==1e9)continue;
                    cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
                }
            }
        }
        int city=-1;
        int countMax=n;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(cost[i][j]<=t){
                    count++;
                }
            }
            if(count<=countMax){
                countMax=count;
                city=i;
            }
        }
        return city;
    }
};