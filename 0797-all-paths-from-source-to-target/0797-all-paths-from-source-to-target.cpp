class Solution {
public:
    void dfs(vector<int>adj[],int n,vector<int> &vis,int s,int d,vector<int>&temp, vector<vector<int>> &ans){
        if(s==d){
        ans.push_back(temp);
        return;
        }
        for(auto it:adj[s]){
            if(!vis[it]){
                vis[it]=1;
                temp.push_back(it);
                dfs(adj,n,vis,it,n-1,temp,ans);
                temp.pop_back();
                vis[it]=0;
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
                adj[i].push_back(it);
            }
        }
        
        vector<int> vis(n,0);
        vector<vector<int>> ans;
        vector<int>temp;
        temp.push_back(0);
        dfs(adj,n,vis,0,n-1,temp,ans);
        return ans;
    }
};

/*if(s==d)
    {
        ans += 1;
        return;
    }
    for(auto it:adj[s])
    {
        if(!vis[it])
        f(adj,v,vis,it,d,ans);
    }
    vis[s] = 0;*/