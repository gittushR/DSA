class Solution {
public:
     void dfs(vector<vector<int>> &adj,vector<int>&vis,int &i,int &V){
        vis[i]=1;
        for(int j=0;j<V;j++){
            if(adj[i][j]==1 && vis[j]!=1)
            {
                dfs(adj,vis,j,V);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected[0].size();
        if(n==0 or n==1)return n;
        vector<int>vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]!=1)
            {
                ans++;
                dfs(isConnected,vis,i,n);
            }
        }
        return ans;
    }
};