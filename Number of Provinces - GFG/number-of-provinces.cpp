//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  int findPar(int node, vector<int>&par){
        if(par[node]==node)return node;
        return par[node]=findPar(par[node],par);
    }
    void unionByRank (int u, int v, vector<int> &rank, vector<int>&par){
        int ult_u=findPar(u,par);
        int ult_v=findPar(v,par);
        if(ult_u==ult_v)return;
        if(rank[ult_u]<rank[ult_v]){
            par[ult_u]=ult_v;
        }else if(rank[ult_v]<rank[ult_u]){
            par[ult_v]=ult_u;
        }else if(rank[ult_v]==rank[ult_u]){
            par[ult_u]=ult_v;
            rank[ult_v]++;
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int>par(V+1);
        for(int i=1;i<=V;i++){
            par[i]=i;
        }
        vector<int> rank(V+1,0);
        
        for (int i=0;i<adj.size();i++){
            for(int j=0;j<adj[0].size();j++){
                if(adj[i][j]==1){
                    unionByRank(i,j,rank,par);
                }
            }
        }
        
        int ans=0;
        for (int i=0;i<V;i++){
            if(findPar(i,par)==i)ans++;
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends