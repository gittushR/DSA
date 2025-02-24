//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool checkCycle(int node, vector<int> &vis, vector<int> &pathVis, vector<vector<int>> &adj){
        vis[node]=1;
        pathVis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]){
                if(checkCycle(it,vis,pathVis,adj))return true;
            }else{
                if(pathVis[it])return true;
            }
        }
        pathVis[node]=0;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(vector<vector<int>> &adj) {
        
        // code here
        int v=adj.size();
        vector<int> vis(v,0);
        vector<int> pathVis(v,0);
        
        for(int i=0;i<v;i++){
            if(!vis[i]){
                if(checkCycle(i,vis,pathVis,adj)==true)return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends