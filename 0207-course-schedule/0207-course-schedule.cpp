class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> adj[n+1];
        for(auto it:pre){
            adj[it[1]].push_back(it[0]);
        }
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)q.push(i);
        }
        int cnt=0;
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            cnt++;
            
            for(auto a:adj[node]){
                indegree[a]--;
                if(indegree[a]==0)q.push(a);
            }
        }
        if(cnt==n)return true;
        return false;
    }
};