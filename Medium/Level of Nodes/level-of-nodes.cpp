//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    // code here
	    queue<pair<int,int>> q;
	    vector<int> vis(V,0);
	    vis[0]=1;
	    q.push({0,0});
	    while(!q.empty()){
	        auto it=q.front();
	        q.pop();
	        int node=it.first;
	        int lvl=it.second;
	        if(node==X)return lvl;
	        for(auto a:adj[node]){
	            if(!vis[a]){
	                q.push({a,lvl+1});
	                vis[a]=1;
	            }
	        }
	    }
	    return -1;
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends