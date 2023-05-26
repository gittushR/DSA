//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to count paths between two vertices in a directed graph.
    void f(vector<int>adj[],int v,int vis[],int s,int d,int &ans){
    if(s==d)
    {
        ans += 1;
        return;
    }
    for(auto it:adj[s])
    {
        if(!vis[it])
        f(adj,v,vis,it,d,ans);
    }
    vis[s] = 0;
}
int countPaths(int V, vector<int> adj[], int source, int destination) {
    // Code here
    int visited[V] = {0};
    int ans = 0;
    f(adj,V,visited,source,destination,ans);
    return ans;
}
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // adj[v].push_back(u);
        }
        int source, destination;
        cin >> source >> destination;
        Solution obj;
        cout << obj.countPaths(V, adj, source, destination) << endl;
    }
    return 0;
}
// } Driver Code Ends