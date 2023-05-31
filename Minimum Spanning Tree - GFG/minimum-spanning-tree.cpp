//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
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
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<int> par(V);
        for(int i=0;i<V;i++)par[i]=i;
        
        vector<int> rank(V,0);
        //{wt,{u,v}}
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                int adjNode = it[0];
                int wt = it[1];
                int node = i;
                edges.push_back({wt, {node, adjNode}});
            }
        }
        sort(edges.begin(), edges.end());
        int sum=0;
        for (auto it : edges) {
            int u=it.second.first;
            int v=it.second.second;
            int wt=it.first;
            //cout<<"*******"<<findPar(u,par)<<"*******"<<findPar(v,par)<<"*******"<<wt<<u<<v<<endl;
            if(findPar(u,par)!=findPar(v,par)){
                sum+=wt;
                //cout<<"****"<<sum<<"****"<<endl;
                unionByRank(u,v,rank,par);
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends