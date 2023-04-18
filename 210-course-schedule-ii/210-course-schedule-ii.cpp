class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        int m=pre.size();
        vector<int> adj[n+1];
        for(int i=0;i<m;i++){
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        
        queue<int> q;
        vector<int> ans;
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        
        for(int i=0;i<n;i++){
            if(indegree[i]==0)q.push(i);
        }
        
        while(!q.empty()){
            int top=q.front();
            q.pop();
            ans.push_back(top);
            for(auto it: adj[top]){
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
        }
        
        if(ans.size()==n)return ans;
        else return {};
    }
};