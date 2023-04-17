// class Solution {
// private:
//     bool dfs(int node, vector<vector<int>> graph, int vis[], int dfsvis[],int check[]){
//         vis[node]=1;
//         dfsvis[node]=1;
//         check[node]=0;
//         for(auto it: graph[node]){
//             if(!vis[it]){
//                 if(dfs(it,graph,vis,dfsvis,check))return true;
//             }else if(dfsvis[it])return true;
//         }
//         check[node]=1;
//         dfsvis[node]=0;
//         return false;
//     }
// public:
//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//         int n=graph.size();
//         vector<int> ans;
//         int vis[n], dfsvis[n], check[n];
//         for(int i=0;i<n;i++){
//             vis[i]=0;
//             dfsvis[i]=0;
//             check[i]=0;
//         }
        
//         for(int i=0;i<n;i++){
//             if(!vis[i]){
//                 dfs(i,graph,vis,dfsvis,check);
//             }
//         }
//         for(int i=0;i<n;i++){
//             if(check[i]==1)ans.push_back(i);
//         }
//         return ans;
//     }
// };
class Solution {
public:
  bool dfs(int node,vector<int> &path,vector<int> &v,vector<int> &check,vector<int> adj[])
  {
      v[node]=1;
      path[node]=1;
      for(auto i:adj[node])
      {
          if(v[i]==0 && path[i]==0)
          {
              if(dfs(i,path,v,check,adj)==true)
              {
                  return true;
              }
          }
          else if(v[i]==1 && path[i]==1)
              {
                  return true;
              }
      }
      path[node]=0;
      check[node]=1;
      return false;
  }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // first of all creating a adjlist
        int V=graph.size(); // total number of rows present in graph
        vector<int> adj[V];
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
            }
        }
        // adj[] has been created..
        // some observations
        // 1.any node part of a cycle cant be a safe node
        // 2.any node leading to cycle node also cant be a safe node

        // finding cycle nodes
        // traversing through each component of graph

       vector<int> v(V,0);
        vector<int> path(V,0);
        vector<int> check(V,0);
        for(int i=0;i<V;i++)
        {
            if(v[i]==0)
            {
                dfs(i,path,v,check,adj);
            }
        }
        vector<int> ans;
        for(int i=0;i<V;i++)
        {
            if(check[i]==1)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};