class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
int i , j  , m , a,b;
long long p,k,l;
vector <vector <int> > adj(n,vector <int>());
m=edges.size();
for(i=0;i<m;i++){
a=edges[i][0]; b=edges[i][1];
adj[a].push_back(b);
adj[b].push_back(a);
}
vector <bool> visited(n,false);
vector <long long> cnt;
k=0;
for(i=0;i<n;i++){
if(!visited[i]){
p = dfs(i,adj,visited);
cnt.push_back(p);
k+=p;
}
}
l=0; p=0;
for(i=0;i<cnt.size();i++){
p+=cnt[i];
l+=(cnt[i]*(k-p));
}
       return l;
}

int dfs(int root, vector <vector <int> > &adj , vector <bool> &visited ){
if(visited[root])return 0;
visited[root]=true;
int i,j,p; p=1;

for(i=0;i<adj[root].size();i++){
j=adj[root][i];
if(!visited[j]){
p+=dfs(j,adj,visited);
}

}

return p;
}

};