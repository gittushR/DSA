//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(cycle(i,vis,adj))return true;
            }
        }
        return false;
    }
    bool cycle(int s, vector<int> &vis, vector<int> adj[]){
        stack<pair<int,int>> st;
        st.push({s,-1});
        vis[s]=1;
        
        while(!st.empty()){
            int node=st.top().first;
            int par=st.top().second;
            
            st.pop();
            
            for(auto it:adj[node]){
                if(!vis[it]){
                    st.push({it,node});
                    vis[it]=1;
                }
                else if(vis[it] && it!=par){
                    return true;
                }
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
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends