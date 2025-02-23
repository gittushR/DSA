//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool checkCycle(int src, vector<int> &vis, vector<vector<int>> &adj){
        queue<pair<int,int>> q;
        q.push({src,-1});
        vis[src]=1;
        while(!q.empty()){
            int node=q.front().first;
            int par= q.front().second;
            q.pop();
            for(auto it: adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push({it,node});
                }else if(it!=par){
                    return true;
                }
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        int v=adj.size();
        vector<int> vis(v,0);
        for(int i=0;i<v;i++){
            if(!vis[i]){
                if(checkCycle(i,vis,adj))return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends