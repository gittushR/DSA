//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int minimumCost(vector<vector<int>>& times, int n, int k) {
        // code here
        vector<pair<int,int>>adj[n+1];
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> time(n+1,1e9);
        time[k]=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        
        while(!pq.empty()){
            int t=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int adjnode=it.first;
                int edw=it.second;
                if(t+edw<time[adjnode]){
                    time[adjnode]=t+edw;
                    pq.push({time[adjnode],adjnode});
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1;i<n+1;i++){
            if(time[i]==1e9)return -1;
            ans=max(ans,time[i]);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size,vector<int>(3));
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i]=temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}

// } Driver Code Ends